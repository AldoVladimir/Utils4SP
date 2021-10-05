/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

#include <stdint.h>
#include <complex.h>

void fft(float* x, float* X_Re, float* X_Im, uint16_t N);
void fftComplex2Real(float* X_Re, float* X_Im, float* x, int N);

//void fftComplex2Real(double complex* X, float* x, int N);
//void fft(float* x, double complex* X, unsigned int N);
