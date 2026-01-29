#include "ifft.h"

int init_ifft(ifft_config* config)
{
    config->ifft_size = IFFT_SIZE;
    config->input    = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * IFFT_SIZE);
    config->output   = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * IFFT_SIZE);

    config->ifft_plan_complex = fftw_plan_dft_1d(IFFT_SIZE, config->input, config->output, FFTW_BACKWARD, FFTW_ESTIMATE);

    return 0;
}

int run_ifft(ifft_config* config, double complex* input_array, double complex* output_array)
{
    memcpy(config->input, input_array, IFFT_SIZE);

    fftw_execute(config->ifft_plan_complex);

    memcpy(output_array, config->output, IFFT_SIZE);

    return 0;
}

int close_ifft(ifft_config* config)
{
    fftw_destroy_plan(config->ifft_plan_complex);
    fftw_free(config->input);
    fftw_free(config->output);

    return 0;
}