/*=========================================================================

  Program: GDCM (Grassroots DICOM). A DICOM library

  Copyright (c) 2006-2011 Mathieu Malaterre
  All rights reserved.
  See Copyright.txt or http:/gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/


/*
 * gdcmscanner -d /path/to/gdcmData/ -t 8,16 -p
 */

static const char * const gdcmMediaStorageDataFiles[][2] = {
{ "LEADTOOLS_FLOWERS-8-PAL-Uncompressed.dcm","1.2.840.10008.5.1.4.1.1.7" },
{ "SIEMENS_GBS_III-16-ACR_NEMA_1.acr", "1.2.840.10008.5.1.4.1.1.4"},
{ "00191113.dcm","1.2.840.10008.5.1.4.1.1.12.1"},
{ "SignedShortLosslessBug.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "gdcm-MR-PHILIPS-16-NonSquarePixels.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "MARCONI_MxTWin-12-MONO2-JpegLossless-ZeroLengthSQ.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "ACUSON-24-YBR_FULL-RLE.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "D_CLUNIE_VL2_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "MR_Philips_Intera_No_PrivateSequenceImplicitVR.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "MR_Philips-Intera_BreaksNOSHADOW.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_MR2_JPLL.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_XA1_JPLL.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "JPEG_LossyYBR.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "ALOKA_SSD-8-MONO2-RLE-SQ.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "PHILIPS_Gyroscan-8-MONO2-Odd_Sequence.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "PHILIPS_Gyroscan-12-MONO2-Jpeg_Lossless.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "MR-MONO2-12-shoulder.dcm","1.2.840.10008.5.1.4.1.1.4"},
//{ "MR_SIEMENS_forceLoad29-1010_29-1020.README.txt (could not be read)},
//{ "ExplicitVRforPublicElementsImplicitVRforShadowElements.README.txt (could not be read)},
{ "D_CLUNIE_RG3_JPLY.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "SIEMENS_SOMATOM-12-ACR_NEMA-ZeroLengthUs.acr","1.2.840.10008.5.1.4.1.1.2"},
{ "PHILIPS_Gyroscan-12-Jpeg_Extended_Process_2_4.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "DICOMDIR_MR_B_VA12A" , "1.2.840.10008.1.3.10" },
{ "MR-MONO2-8-16x-heart.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "SIEMENS_ImageLocationUN.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "US-PAL-8-10x-echo.dcm","1.2.840.10008.5.1.4.1.1.3.1"},
{ "PHILIPS_Brilliance_ExtraBytesInOverlay.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "SIEMENS_MAGNETOM-12-MONO2-Uncompressed.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "MR-MONO2-12-an2.acr","1.2.840.10008.5.1.4.1.1.4"},
{ "LEADTOOLS_FLOWERS-8-PAL-RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "US-RGB-8-esopecho.dcm","1.2.840.10008.5.1.4.1.1.6"},
{ "GE_RHAPSODE-16-MONO2-JPEG-Fragments.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "CT-SIEMENS-Icone-With-PaletteColor.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "gdcm-ACR-LibIDO.acr" , "1.2.840.10008.5.1.4.1.1.7"}, // COMPAT
{ "LEADTOOLS_FLOWERS-16-MONO2-Uncompressed.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "FUJI-10-MONO1-ACR_NEMA_2.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "D_CLUNIE_CT1_RLE.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "undefined_length_un_vr.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_MR4_JPLL.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "PET-cardio-Multiframe-Papyrus.dcm", "" },
{ "dicomdir_Pms_WithVisit_WithPrivate_WithStudyComponents" , "1.2.840.10008.1.3.10"},
{ "CT_16b_signed-UsedBits13.dcm","1.2.840.10008.5.1.4.1.1.2"},
//{ "TestAllEntryVerifyReference.txt (could not be read)},
{ "DX_J2K_0Padding.dcm","1.2.840.10008.5.1.4.1.1.1.1"},
{ "KODAK_CompressedIcon.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "D_CLUNIE_CT2_JPLL.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "DermaColorLossLess.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "DICOMDIR" , "1.2.840.10008.1.3.10" },
{ "LIBIDO-24-ACR_NEMA-Rectangle.dcm", "" },
{ "GE_GENESIS-16-MONO2-Uncompressed-UnusualVR.dcm","1.2.840.10008.5.1.4.1.1.4"},
//{ "MR-SIEMENS-DICOM-WithOverlays.README.txt (could not be read)},
{ "D_CLUNIE_NM1_JPLY.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "MR_Philips_Intera_SwitchIndianess_noLgtSQItem_in_trueLgtSeq.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "LEADTOOLS_FLOWERS-24-RGB-JpegLossy.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_CT1_J2KR.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "LEADTOOLS_FLOWERS-16-MONO2-RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "US-RGB-8-epicard.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "D_CLUNIE_MR3_RLE.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "test.acr" ,"1.2.840.10008.5.1.4.1.1.7"}, // COMPAT
{ "LEADTOOLS_FLOWERS-8-MONO2-Uncompressed.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "US-IRAD-NoPreambleStartWith0005.dcm","1.2.840.10008.5.1.4.1.1.6"},
{ "D_CLUNIE_RG2_JPLL.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "ELSCINT1_PMSCT_RLE1.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "DMCPACS_ExplicitImplicit_BogusIOP.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "MR_ELSCINT1_00e1_1042_SQ_feff_00e0_Item.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "LIBIDO-16-ACR_NEMA-Volume.dcm", "" },
//{ "Changelog (could not be read)},
//{ "ELSCINT1_LOSSLESS_RICE.txt (could not be read)},
{ "MR-SIEMENS-DICOM-WithOverlays.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "SIEMENS_MOSAIC_12BitsStored-16BitsJPEG.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "JDDICOM_Sample2-dcmdjpeg.dcm", "" },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq2.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_MR3_JPLY.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "MR_Philips_Intera_PrivateSequenceExplicitVR_in_SQ_2001_e05f_item_wrong_lgt_use_NOSHADOWSEQ.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "TheralysGDCM120Bug.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "PrivateGEImplicitVRBigEndianTransferSyntax16Bits.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "US-GE-4AICL142.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "3E768EB7.dcm","1.2.840.10008.5.1.4.1.1.2"},
//{ "gdcm-MR-PHILIPS-16-Multi-Seq.README.txt (could not be read)},
{ "SIEMENS_Sonata-16-MONO2-Value_Multiplicity.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "GE_MR_0025xx1bProtocolDataBlock.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "MR_GE_with_Private_Compressed_Icon_0009_1110.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "ExplicitVRforPublicElementsImplicitVRforShadowElements.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_SC1_JPLY.dcm","1.2.840.10008.5.1.4.1.1.7"},
//{ "imagesWithOverlays.README.txt (could not be read)},
{ "CT-MONO2-16-chest.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_MR4_RLE.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "gdcm-CR-DCMTK-16-NonSamplePerPix.dcm" , "" },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq1.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "ELSCINT1_JP2vsJ2K.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_CT2_RLE.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_MR2_RLE.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "OT-MONO2-8-a7.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "MR-MONO2-16-head.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "PICKER-16-MONO2-No_DicomV3_Preamble.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "gdcm-JPEG-Extended.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "MR-MONO2-12-angio-an1.acr", ""},
{ "BugGDCM2_UndefItemWrongVL.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_MR1_RLE.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "ELSCINT1_LOSSLESS_RICE.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "dicomdir_Pms_With_heavy_embedded_sequence" , "1.2.840.10008.1.3.10" },
{ "PICKER-16-MONO2-Nested_icon.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_VL4_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_RG1_RLE.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "JDDICOM_Sample2.dcm", "" },
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq3.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "CT-MONO2-8-abdo.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_SC1_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "LEADTOOLS_FLOWERS-24-RGB-JpegLossless.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "LIBIDO-8-ACR_NEMA-Lena_128_128.acr" , "" },
{ "D_CLUNIE_RG3_JPLL.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "SIEMENS_CSA2.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "SIEMENS_GBS_III-16-ACR_NEMA_1-ULis2Bytes.dcm", "" },
{ "LJPEG_BuginGDCM12.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "CT-SIEMENS-MissingPixelDataInIconSQ.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "05115014-mr-siemens-avanto-syngo-with-palette-icone.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "libido1.0-vol.acr" , "" },
{ "MR_Spectroscopy_SIEMENS_OF.dcm","1.2.840.10008.5.1.4.1.1.4.2"},
{ "GE_CT_With_Private_compressed-icon.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_XA1_JPLY.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "012345.002.050.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "TOSHIBA_MRT150-16-MONO2-ACR_NEMA_2.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "LEADTOOLS_FLOWERS-8-MONO2-JpegLossy.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "gdcm-US-ALOKA-16.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "THERALYS-12-MONO2-Uncompressed-Even_Length_Tag.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_CT1_JPLL.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "rle16loo.dcm","1.2.840.10008.5.1.4.1.1.3.1"},
{ "D_CLUNIE_US1_RLE.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "LEADTOOLS_FLOWERS-8-MONO2-RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "RadBWLossLess.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "dicomdir_Acusson_WithPrivate_WithSR" , "1.2.840.10008.1.3.10"},
{ "D_CLUNIE_MR1_JPLY.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "GE_DLX-8-MONO2-PrivateSyntax.dcm","1.2.840.10008.5.1.4.1.1.12.1"},
{ "gdcm-JPEG-LossLess3a.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "TG18-CH-2k-01.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "OT-PAL-8-face.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_NM1_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "rle16sti.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "GE_GENESIS-16-MONO2-WrongLengthItem.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_CT1_J2KI.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "SIEMENS_MAGNETOM-12-MONO2-FileSeq0.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "LEADTOOLS_FLOWERS-24-RGB-Uncompressed.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_MR4_JPLY.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_RG3_RLE.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "SIEMENS-12-Jpeg_Process_2_4-Lossy-a.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "DICOMDIR-Philips-EasyVision-4200-Entries", "1.2.840.10008.1.3.10"},
{ "CT-MONO2-16-brain.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_RG2_JPLY.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "MAROTECH_CT_JP2Lossy.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "D_CLUNIE_MR1_JPLL.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "ITK_GDCM124_MultiframeSecondaryCaptureInvalid.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "dicomdir_With_embedded_icons", "1.2.840.10008.1.3.10"},
{ "SIEMENS_MAGNETOM-12-ACR_NEMA_2-Modern.dcm", "" },
{ "MR_SIEMENS_forceLoad29-1010_29-1020.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "simpleImageWithIcon.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_MR3_JPLL.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_RG1_JPLL.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "US-MONO2-8-8x-execho.dcm","1.2.840.10008.5.1.4.1.1.3"},
{ "XA-MONO2-8-12x-catheter.dcm","1.2.840.10008.5.1.4.1.1.12.1"},
//{ "TheralysGDCM120Bug.README.txt (could not be read)},
{ "GE_LOGIQBook-8-RGB-HugePreview.dcm","1.2.840.10008.5.1.4.1.1.7"},
//{ "MR_Philips_Intera_PrivateSequenceImplicitVR.README.txt (could not be read)},
{ "gdcm-MR-SIEMENS-16-2.acr", ""},
{ "gdcm-MR-PHILIPS-16-Multi-Seq.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_XA1_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "NM-MONO2-16-13x-heart.dcm","1.2.840.10008.5.1.4.1.1.20"},
{ "gdcm-JPEG-LossLessThoravision.dcm","1.2.840.10008.5.1.4.1.1.1"},
//{ "SIEMENS_MAGNETOM-12-MONO2-GDCM12-VRUN.txt (could not be read)},
{ "GE_DLX-8-MONO2-Multiframe.dcm","1.2.840.10008.5.1.4.1.1.12.1"},
{ "PHILIPS_Intera-16-MONO2-Uncompress.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_MR2_JPLY.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "05148044-mr-siemens-avanto-syngo.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_VL3_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_RG2_RLE.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "SIEMENS_MAGNETOM-12-MONO2-GDCM12-VRUN.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "KODAK-12-MONO1-Odd_Terminated_Sequence.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "SIEMENS-MR-RGB-16Bits.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "CR-MONO1-10-chest.dcm","1.2.840.10008.5.1.4.1.1.1"},
{ "DX_GE_FALCON_SNOWY-VOI.dcm","1.2.840.10008.5.1.4.1.1.1.1"},
{ "US-IRAD-NoPreambleStartWith0003.dcm","1.2.840.10008.5.1.4.1.1.6"},
{ "MR-Brucker-CineTagging-NonSquarePixels.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "D_CLUNIE_VL6_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "MR_Philips_Intera_PrivateSequenceImplicitVR.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "fffc0000UN.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "CT-MONO2-12-lomb-an2.acr" , "" },
{ "SIEMENS_Sonata-12-MONO2-SQ.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "ACUSON-24-YBR_FULL-RLE-b.dcm","1.2.840.10008.5.1.4.1.1.6.1"},
{ "CT-MONO2-16-ankle.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "GE_DLX-8-MONO2-Multiframe-Jpeg_Lossless.dcm","1.2.840.10008.5.1.4.1.1.12.1"},
{ "MR-SIEMENS-DICOM-WithOverlays-extracted-overlays.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "CT-MONO2-16-ort.dcm","1.2.840.10008.5.1.4.1.1.2"},
{ "LEADTOOLS_FLOWERS-16-MONO2-JpegLossless.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_NM1_JPLL.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "D_CLUNIE_VL1_RLE.dcm","1.2.840.10008.5.1.4.1.1.7"},
{ "IM-0001-0066.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "SIEMENS_MAGNETOM-12-MONO2-VRUN.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "PhilipsInteraSeqTermInvLen.dcm","1.2.840.10008.5.1.4.1.1.4"},
{ "PHILIPS_GDCM12xBug.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "OsirixFake16BitsStoredFakeSpacing.dcm", "1.2.840.10008.5.1.4.1.1.7" },
{ "IM-0001-0066.CommandTag00.dcm", "1.2.840.10008.5.1.4.1.1.4" },
{ "AMIInvalidPrivateDefinedLengthSQasUN.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "GDCMJ2K_TextGBR.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "MR16BitsAllocated_8BitsStored.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "D_CLUNIE_CT1_JLSL.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "JPEGDefinedLengthSequenceOfFragments.dcm" , "1.2.840.10008.5.1.4.1.1.2" },
{ "PHILIPS_GDCM12xBug2.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "DCMTK_JPEGExt_12Bits.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "UnexpectedSequenceDelimiterInFixedLengthSequence.dcm" , "1.2.840.10008.5.1.4.1.1.20" },
{ "NM_Kakadu44_SOTmarkerincons.dcm" , "1.2.840.10008.5.1.4.1.1.1" },
{ "D_CLUNIE_CT1_JLSN.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "TOSHIBA_J2K_SIZ1_PixRep0.dcm",  "1.2.840.10008.5.1.4.1.1.2"},
{ "TOSHIBA_J2K_SIZ0_PixRep1.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "TOSHIBA_J2K_OpenJPEGv2Regression.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "NM-PAL-16-PixRep1.dcm", "1.2.840.10008.5.1.4.1.1.20" },
{ "MEDILABInvalidCP246_EVRLESQasUN.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "JPEGInvalidSecondFrag.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "ELSCINT1_PMSCT_RLE1_priv.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "unreadable.dcm", "1.2.840.10008.5.1.4.1.1.2" },
{ "SC16BitsAllocated_8BitsStoredJPEG.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "SC16BitsAllocated_8BitsStoredJ2K.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "SIEMENS_SYNGO-12-MONO2-LUTWrongLength512.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "JPEGNote_empty.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "JPEGLS_CharLS_10742.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "JPEGLosslessYBR_FULL_422.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "JPEGNote_missing.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "JPEGNote_bogus.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "RLEDebianBug816607Orig.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "IllegalGroup2ImplicitTS.dcm" , "1.2.840.10008.5.1.4.1.1.1" },
{ "JPEG_LS_InvalidEscapeSequence_COM_padding.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "LengthOfItemLarger.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "GE_MR_0025xx1bProtocolDataBlockXML.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "MITRA_CORNELL.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "EmptyIcon_Bug417.dcm" , "1.2.840.10008.5.1.4.1.1.2" },
{ "EnhancedWithIPPPerFrameIOPShared.dcm" , "1.2.840.10008.5.1.4.1.1.13.1.2" },
{ "FUJI-ffff-MONO1-J2K.dcm" , "1.2.840.10008.5.1.4.1.1.1" },
{ "JPEGLosslessSeNonZero.dcm" , "1.2.840.10008.5.1.4.1.1.7" },
{ "US-YBR_FULL_422-EVRLE.dcm" , "1.2.840.10008.5.1.4.1.1.6.1" },
{ "PET-GE-dicomwrite-PixelDataSQUN.dcm" , "1.2.840.10008.5.1.4.1.1.128" },
{ "Osirix10vs8BitsStored.dcm" , "1.2.840.10008.5.1.4.1.1.4" },
{ "Bug_Siemens_PrivateIconNoItem.dcm" , "1.2.840.10008.5.1.4.1.1.2" },
{ "HardcopyColor_YBR_RCT_J2K_PC1.dcm" , "1.2.840.10008.5.1.1.30" },
{ "PET-GE-dicomwrite-PixelDataSQUNv2.dcm" , "1.2.840.10008.5.1.4.1.1.128" },
{ "PET-GE-dicomwrite-PixelDataSQUNv3.dcm" , "1.2.840.10008.5.1.4.1.1.128" },
{ "MEDILABValidCP246_EVRLESQasOB.dcm" , "1.2.840.10008.5.1.4.1.1.2" },

/* Stopping condition */
{ nullptr ,nullptr }
};
