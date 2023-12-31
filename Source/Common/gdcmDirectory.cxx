/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmDirectory.h"
#include "gdcmTrace.h"

#include <iterator>
#include <assert.h>
#include <errno.h>
#include <sys/stat.h>  //stat function
#include <string.h> // strerror

#ifdef _MSC_VER
  #include <windows.h>
  #include <direct.h>
#else
  #include <dirent.h>
  #include <sys/types.h>
#endif

namespace gdcm
{

unsigned int Directory::Load(FilenameType const &name, bool recursive)
{
  Filenames.clear(); // clear previous
  Directories.clear(); // clear previous
  if( System::FileIsDirectory( name.c_str() ) )
      {
      Toplevel = name;
      return Explore( Toplevel, recursive );
      }
  return 0;
}

#ifdef _MSC_VER
static inline std::string ToUtf8(std::wstring const &str) {
  std::string ret;
  int len = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(),
                                nullptr, 0, NULL, NULL);
  if (len > 0) {
    ret.resize(len);
    WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), &ret[0],
                        len, NULL, NULL);
  }
  return ret;
}
#endif

unsigned int Directory::Explore(FilenameType const &name, bool recursive)
{
  unsigned int nFiles = 0;
#ifdef _MSC_VER
  std::wstring fileName;
  std::wstring dirName = System::ConvertToUNC(name.c_str());
  Directories.push_back(ToUtf8(dirName));
  WIN32_FIND_DATAW fileData;
  if ('\\' == dirName[dirName.size() - 1])
    dirName = dirName.substr(0, dirName.size() - 1);
  if ('/' != dirName[dirName.size() - 1]) dirName.push_back('/');
  assert( '/' == dirName[dirName.size()-1] );
  const std::wstring firstfile = dirName+L"*";
  HANDLE hFile = FindFirstFileW(firstfile.c_str(), &fileData);

  for(BOOL b = (hFile != INVALID_HANDLE_VALUE); b;
    b = FindNextFileW(hFile, &fileData))
    {
    fileName = fileData.cFileName;
    if ( fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
      {
      // Need to check for . and .. to avoid infinite loop
      if ( fileName != L"." && fileName != L".."
        && fileName[0] != '.' // discard any hidden dir
        && recursive )
        {
        nFiles += Explore(ToUtf8(dirName + fileName), recursive);
        }
      }
    else
      {
      if (fileName[0] != '.') // discard "unix like" hidden files such as .git in submodules
        {
        Filenames.push_back(ToUtf8(dirName+fileName));
        nFiles++;
        }
      }
    }
  DWORD dwError = GetLastError();
  if (hFile != INVALID_HANDLE_VALUE) FindClose(hFile);
  if (dwError != ERROR_NO_MORE_FILES)
    {
    //gdcmErrorMacro("FindNextFile error. Error is " << dwError);
    return 0;
    }

#else
  std::string fileName;
  std::string dirName = name;
  // assert( System::FileIsDirectory( dirName ) );
  Directories.push_back(dirName);
  // Real POSIX implementation: scandir is a BSD extension only, and doesn't
  // work on debian for example

  DIR* dir = opendir(dirName.c_str());
  if (!dir)
    {
    const char *str = strerror(errno); (void)str;
    gdcmErrorMacro( "Error was: " << str << " when opening directory: " << dirName );
    return 0;
    }

  // According to POSIX, the dirent structure contains a field char d_name[]
  // of unspecified size, with at most NAME_MAX characters preceding the
  // terminating null character. Use of other fields will harm the  porta-
  // bility of your programs.

  struct stat buf;
  dirent *d;
  if ('/' != dirName[dirName.size()-1]) dirName.push_back('/');
  assert( '/' == dirName[dirName.size()-1] );
  for (d = readdir(dir); d; d = readdir(dir))
    {
    fileName = dirName + d->d_name;
    if( stat(fileName.c_str(), &buf) != 0 )
      {
      const char *str = strerror(errno); (void)str;
      gdcmErrorMacro( "Last Error was: " << str << " for file: " << fileName );
      break;
      }
    if ( S_ISREG(buf.st_mode) )    //is it a regular file?
      {
      if( d->d_name[0] != '.' )
        {
        Filenames.push_back( fileName );
        nFiles++;
        }
      }
    else if ( S_ISDIR(buf.st_mode) ) //directory?
      {
      // discard . and ..
      if( strcmp( d->d_name, "." ) == 0
        || strcmp( d->d_name, ".." ) == 0
        || d->d_name[0] == '.' ) // discard any hidden dir
        continue;
      assert( d->d_name[0] != '.' ); // hidden directory ??
      if ( recursive )
        {
        nFiles += Explore( fileName, recursive);
        }
      }
    else
      {
      gdcmErrorMacro( "Unexpected type for file: " << fileName );
      break;
      }
    }
  if( closedir(dir) != 0 )
    {
    const char *str = strerror(errno); (void)str;
    gdcmErrorMacro( "Last error was: " << str << " when closing directory: " << fileName );
    }
#endif

  return nFiles;
}

void Directory::Print(std::ostream &_os) const
{
  // FIXME Both structures are FilenamesType I could factorize the code
  _os << "Directories: ";
  if( Directories.empty() )
    _os << "(None)" << std::endl;
  else
    {
    std::copy(Directories.begin(), Directories.end(),
      std::ostream_iterator<std::string>(_os << std::endl, "\n"));
    }
  _os << "Filenames: ";
  if( Filenames.empty() )
    _os << "(None)" << std::endl;
  else
    {
    std::copy(Filenames.begin(), Filenames.end(),
      std::ostream_iterator<std::string>(_os << std::endl, "\n"));
    }
}

} // end namespace gdcm
