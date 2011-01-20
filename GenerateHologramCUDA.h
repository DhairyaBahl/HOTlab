/*   
   Header file for GenerateHologramCUDA
   Hologram generating algorithms for CUDA Devices
   Copyright 2009, 2010, 2011 Martin Persson 
   martin.persson@physics.gu.se


   This file is part of GenerateHologramCUDA.

    GenerateHologramCUDA is free software: you can redistribute it and/or 
    modify it under the terms of the GNU General Public License as published 
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GenerateHologramCUDA is distributed in the hope that it will be 
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with GenerateHologramCUDA.  If not, see <http://www.gnu.org/licenses/>.
*/
////////////////////////////////////////////////////////////////////////////////
// Includes

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <cutil.h>
#include <cufft.h>

// Complex data type
typedef float2 cufftComplex;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define block_size 256

////////////////////////////////////////////////////////////////////////////////
//Global variables
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
// declarations

__global__ void computeDelta(float *d_x, 
							 float *d_y, 
							 float *d_z, 
							 float *delta, 
							 float *ei_delta_re, 
							 float *ei_delta_im, 
							 int N_spots, 
							 int N_pixels, 
							 int data_w);
__global__ void computeV(float *d_Vre, 
						 float *d_Vim, 
						 float *d_pSLM, 
						 float *delta, 
						 int N, 
						 int N_spots);
__global__ void computeWeights(float *g_Vre, 
							   float *g_Vim, 
							   int N_spots,
							   float *g_weights,
							   int iteration,
							   float *g_amps_o,
							   float *g_I,
							   int N_pixels);
__global__ void computePhi(float *d_Vre, 
						   float *d_Vim, 
						   float *d_Phi, 
						   float *d_ei_dre, 
						   float *d_ei_dim, 
						   int N_pixels, 
						   int N_spots, 
						   float *weights, 
						   int iteration, 
						   float *pSLM_start, 
						   float alpha, 
						   float *amps);
__global__ void f2uc(unsigned char *uc, 
					 float *f, 
					 int N_pixels, 
					 unsigned char *g_LUT, 
					 int use_linLUT, 
					 int data_w);
__global__ void uc2f(float *f, 
					 unsigned char *uc, 
					 int N);
void reduce(int size, 
			int threads, 
			int blocks, 
			float *d_idata, 
			float *d_odata, 
			int offset);
void Reduce(int  n, 
			int maxThreads, 
			int maxBlocks, 
			float* d_idata, 
			float* d_odata, 
			int offset);



__global__ void LensesAndPrisms(float *g_x, 
								float *g_y, 
								float *g_z, 
								float *g_a, 
								unsigned char *g_SLMuc, 
								int N_spots, 
								unsigned char *g_LUT, 
								int use_linLUT, 
								int data_w);
__global__ void computePhiNew(float *g_x, 
							float *g_y, 
							float *g_z, 
							float *g_I, 
							float *g_SpotsRe, 
							float *g_SpotsIm, 
							float *g_Phi, 
							int N_pixels, 
							int N_spots, 
							float *g_weights, 
							int iteration, 
							float *g_pSLM_start, 
							float RPC, 
							float *g_amps);
__global__ void transformToFarfield(float *g_x, 
									float *g_y, 
									float *g_z, 
									float *g_pSLM, 
									float *g_Vre, 
									float *g_Vim,
									int N_spots, 
									unsigned int n, 
									int data_w);



