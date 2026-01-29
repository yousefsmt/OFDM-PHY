#ifndef PHY_SOURCE_IFFT_H_
#define PHY_SOURCE_IFFT_H_

/*
 * OFDM Physical Layer Simulation
 * Copyright (C) 2026 Yousef
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <assert.h>
#include <fftw3.h>
#include <complex.h>
#include <string.h>

#define NORM_FACTOR(size) (1/sqrt((double)(size)))
#define IFFT_SIZE 128

typedef struct
{
    size_t        ifft_size;
    fftw_complex* input;
    fftw_complex* output;
    fftw_plan     ifft_plan_complex;
}ifft_config;


int init_ifft(ifft_config* config);
int run_ifft(ifft_config* config, double complex* input_array, double complex* output_array);
int close_ifft(ifft_config* config);

#endif // !PHY_SOURCE_IFFT_H_