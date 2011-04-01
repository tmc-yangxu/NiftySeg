#pragma once

#include "_seg_common.h"
#include "_seg_matrix.h"
#include "_seg_FMM.h"
#include "_seg_BiasCorrection.h"


void printloglik(int iter,
                 PrecisionTYPE loglik,
                 PrecisionTYPE oldloglik);

void calcM_mask(nifti_image * T1,
                PrecisionTYPE * Expec,
                PrecisionTYPE * BiasField,
                int * S2L,
                PrecisionTYPE * M,
                PrecisionTYPE * V,
                PrecisionTYPE * M_MAP,
                PrecisionTYPE * V_MAP,
                ImageSize * CurrSizes,
                int verbose);

void calcM_mask_LoAd(nifti_image * T1,
                     PrecisionTYPE * Expec,
                     PrecisionTYPE * BiasField,
                     int * S2L,
                     PrecisionTYPE * M,
                     PrecisionTYPE * V,
                     ImageSize * CurrSizes,
                     int verbose,
                     bool PVon);

void calcM(nifti_image * T1,
           PrecisionTYPE * Expec,
           PrecisionTYPE * BiasField,
           PrecisionTYPE * M,
           PrecisionTYPE * V,
           PrecisionTYPE * M_MAP,
           PrecisionTYPE * V_MAP,
           ImageSize * CurrSizes,
           int verbose);

void calcE(nifti_image * T1,
           PrecisionTYPE * MRF,
           PrecisionTYPE * Expec,
           PrecisionTYPE * loglik,
           PrecisionTYPE * BiasField,
           PrecisionTYPE * M,
           PrecisionTYPE * V,
           ImageSize * CurrSizes,
           int verbose);

void calcE_mask(nifti_image * T1,
                PrecisionTYPE * IterPrior,
                PrecisionTYPE * Expec,
                PrecisionTYPE * loglik,
                PrecisionTYPE * BiasField,
                int * S2L,
                PrecisionTYPE * M,
                PrecisionTYPE * V,
                ImageSize * CurrSizes,
                int verbose);
/*
void calcE_aprox(nifti_image * T1,
                 PrecisionTYPE * MRF,
                 PrecisionTYPE * Expec,
                 PrecisionTYPE * loglik,
                 PrecisionTYPE * BiasField,
                 PrecisionTYPE * M,
                 PrecisionTYPE * V,
                 ImageSize * CurrSizes,
                 int verbose);

void calcE_mask_aprox(nifti_image * T1,
                      PrecisionTYPE * IterPrior,
                      PrecisionTYPE * Expec,
                      PrecisionTYPE * loglik,
                      PrecisionTYPE * BiasField,
                      int * S2L,
                      PrecisionTYPE * M,
                      PrecisionTYPE * V,
                      ImageSize * CurrSizes,
                      int verbose);
*/
void Relax_Priors(PrecisionTYPE * Priors,
                  PrecisionTYPE * Expec,
                  PrecisionTYPE * MRF,
                  int * S2L,
                  int * L2S,
                  float RelaxFactor,
                  PrecisionTYPE * G,
                  PrecisionTYPE ba,
                  PrecisionTYPE be,
                  ImageSize * CurrSizes,
                  SEG_PARAM * segment_param);

void Normalize_Image(nifti_image * T1,
                     ImageSize * CurrSizes,
                     bool verbose);

void Normalize_Image_mask(nifti_image * T1,
                          nifti_image * Mask,
                          ImageSize * CurrSizes,
                          bool verbose);

void RelaxPriors( PrecisionTYPE * Expec,
                  PrecisionTYPE * MRF,
                  int * S2L ,int * L2S ,
                  ImageSize CurrSizes,
                  int class_with_CSF);

void Convert_to_PV(nifti_image * T1,
                   PrecisionTYPE * BiasField,
                   PrecisionTYPE * ShortPrior,
                   PrecisionTYPE * Expec,
                   PrecisionTYPE * MRF,
                   PrecisionTYPE * M,
                   PrecisionTYPE * V,
                   int * S2L,
                   int * L2S,
                   ImageSize * CurrSizes,
                   SEG_PARAM * segment_param);

bool * binarise_image(PrecisionTYPE * SingleImage,
                      PrecisionTYPE Threshold,
                      ImageSize * CurrSizes);

void Create_GH_5class(PrecisionTYPE * G,
                      PrecisionTYPE * H,
                      PrecisionTYPE ba,
                      PrecisionTYPE be,
                      PrecisionTYPE ratio,
                      SEG_PARAM * segment_param);

void Create_GH_7class(PrecisionTYPE * G,
                      PrecisionTYPE * H,
                      PrecisionTYPE ba,
                      PrecisionTYPE be,
                      PrecisionTYPE ratio,
                      SEG_PARAM * segment_param);

void Relax_Priors_Share(PrecisionTYPE * Priors,
                        PrecisionTYPE * Expec,
                        float RelaxFactor,
                        PrecisionTYPE * G,
                        PrecisionTYPE be,
                        ImageSize * CurrSizes);

void seg_convert2binary(nifti_image *image,
                        float thresh);

void Normalize_T1_and_MV(nifti_image * T1,
                         nifti_image * Mask,
                         PrecisionTYPE * M,
                         PrecisionTYPE * V,
                         ImageSize * CurrSizes);

void Normalize_NaN_Priors(nifti_image * Priors,
                          bool verbose);

void Normalize_NaN_Priors_mask(nifti_image * Priors,
                               nifti_image * Mask,
                               bool verbose);

void Convert_WM_and_GM_to_PV(nifti_image * T1,
                             PrecisionTYPE * BiasField,
                             PrecisionTYPE * ShortPrior,
                             PrecisionTYPE * Expec,
                             int * S2L,
                             PrecisionTYPE * M,
                             PrecisionTYPE * V,
                             ImageSize * CurrSize);

void Gaussian_Filter_Short_4D(PrecisionTYPE * ShortData,
                              int * S2L,
                              int * L2S,
                              PrecisionTYPE gauss_std,
                              ImageSize * CurrSizes,
                              int class_with_CSF);

PrecisionTYPE * Gaussian_Filter_4D(PrecisionTYPE * LongData,
                                   PrecisionTYPE gauss_std,
                                   ImageSize * CurrSizes);


PrecisionTYPE * Gaussian_Filter_4D_inside_mask(PrecisionTYPE * LongData,
                                               bool * mask,
                                                PrecisionTYPE gauss_std,
                                                ImageSize * CurrSizes);

void Create_diagonal_GH_Nclass(PrecisionTYPE * G,
                               PrecisionTYPE * H,
                               PrecisionTYPE ratio,
                               SEG_PARAM * segment_param);

void Sulci_and_gyri_correction(PrecisionTYPE * MRF_Beta,
                               PrecisionTYPE * ShortPrior,
                               PrecisionTYPE * Expec,
                               PrecisionTYPE *MRF,
                               int * S2L,
                               int * L2S,
                               ImageSize *CurrSizes,
                               SEG_PARAM *segment_param);

nifti_image * Copy_ShortExpec_to_Result(nifti_image * T1,
                                        PrecisionTYPE * Expec,
                                        PrecisionTYPE * BiasField,
                                        PrecisionTYPE * BiasFieldCoefs,
                                        int * S2L,
                                        nifti_image * Priors,
                                        SEG_PARAM * segment_param,
                                        PrecisionTYPE * M,
                                        ImageSize * CurrSizes);

int * Create_Long_2_Short_Matrix_from_NII(nifti_image * Mask);

int * Create_Short_2_Long_Matrix_from_NII(nifti_image * Mask,
                                          int * shortsize);

PrecisionTYPE * Create_cArray_from_Prior_mask( nifti_image * Mask,
                                               nifti_image * Priors,
                                               int numclass,
                                               bool PV_ON);

PrecisionTYPE * Create_cArray_from_Prior(nifti_image * Priors,
                                         int numclass,
                                         bool PV_ON);

PrecisionTYPE * Create_cArray_from_3D_image(nifti_image * Mask,
                                            nifti_image * SourceImage);

int * Create_Short_2_Long_Matrix_from_Carray(bool * Mask,
                                             int * shortsize,
                                             int nvox);

int *  Create_Long_2_Short_Matrix_from_Carray(bool * Mask,
                                              int nvox);

nifti_image * Copy_Single_ShortImage_to_Result(PrecisionTYPE * SingleImage,
                                               int * Short_2_Long_Indices,
                                               nifti_image * Priors,
                                               char * filename,
                                               ImageSize * CurrSizes);

template <class DTYPE> void seg_convert2binary_data(nifti_image *image,
                                                    float thresh);

nifti_image * Copy_Expec_and_BiasCorrected_to_Result_mask(PrecisionTYPE * Expec,
                                                          PrecisionTYPE * BiasField,
                                                          int * Short_2_Long_Indices,
                                                          nifti_image * T1,
                                                          char * filename,
                                                          ImageSize * CurrSizes);
nifti_image * Copy_Expec_and_BiasCorrected_to_Result(PrecisionTYPE * Expec,
                                                     PrecisionTYPE * BiasField,
                                                     nifti_image * T1,
                                                     char * filename,
                                                     ImageSize * CurrSizes);

nifti_image * Copy_Expec_to_Result_mask(PrecisionTYPE * Expec,
                                        int * Short_2_Long_Indices,
                                        nifti_image * T1,
                                        char * filename,
                                        ImageSize * CurrSizes);

nifti_image * Copy_Expec_to_Result_Neonate_mask(PrecisionTYPE * Expec,
                                                int * Short_2_Long_Indices,
                                                int * Long_2_Short_Indices,
                                                nifti_image * T1,
                                                float * Biasfield,
                                                float * M,
                                                char * filename,
                                                ImageSize * CurrSizes);


nifti_image * Copy_Expec_to_Result(PrecisionTYPE * Expec,
                                   nifti_image * T1,
                                   char * filename,
                                   ImageSize * CurrSizes);

void PriorWeight_mask(float * ShortPrior,
                      nifti_image * Priors,
                      float * Expec,
                      float GaussKernelSize,
                      float RelaxFactor,
                      int * S2L,
                      int * L2S,
                      ImageSize * CurrSizes,
                      int verbose_level);

nifti_image * Copy_single_image_to_Result(int * Mask,
                                          nifti_image * Original,
                                          char * filename);

nifti_image * Copy_single_image_to_Result(bool * Mask,
                                          nifti_image * Original,
                                          char * filename);
nifti_image * Copy_single_image_to_Result(float * Mask,
                                          nifti_image * Original,
                                          char * filename);

void quickSort(int *arr, int elements);

nifti_image * Get_Bias_Corrected(float * BiasField,
                                      nifti_image * T1,
                                      char * filename,
                                      ImageSize * CurrSizes);

nifti_image * Get_Bias_Corrected_mask(float * BiasFieldCoefs,
                                      nifti_image * T1,
                                      char * filename,
                                      ImageSize * CurrSizes,
                                      int biasOrder);

float * seg_norm4NCC(nifti_image * BaseImage,nifti_image * LNCC,nifti_image * Lables,int distance,ImageSize * CurrSizes);

extern "C++" template <class NewTYPE>
void seg_changeDatatype(nifti_image *image);