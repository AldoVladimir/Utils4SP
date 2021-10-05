///* Fast Fourier Transform
// * Cooley-Tukey algorithm with 2-radix DFT
// */
//
//#include <complex.h>
//
//#define PI 3.14159265358979323846
//
//void fft_slow(int* x, double complex* X, unsigned int N) {
//    unsigned int n, k;
//
//    // Iterate through, allowing X_K = sum_N of the complex frequencies.
//    for (k = 0; k < N; k++) {
//        for (n = 0; n < N; n++) {
//            X[k] += x[n] * cexp(-2 * PI * I * n * k / N);
//        }
//    }
//}
//
//void fft_radix2(int* x, double complex* X, unsigned int N, unsigned int s) {
//    unsigned int k;
//    double complex t;
//
//    // At the lowest level pass through (delta T=0 means no phase).
//    if (N == 1) {
//        X[0] = x[0];
//        return;
//    }
//
//    // Cooley-Tukey: recursively split in two, then combine beneath.
//    fft_radix2(x, X, N/2, 2*s);
//    fft_radix2(x+s, X + N/2, N/2, 2*s);
//
//    for (k = 0; k < N/2; k++) {
//        t = X[k];
//        X[k] = t + cexp(-2 * PI * I * k / N) * X[k + N/2];
//        X[k + N/2] = t - cexp(-2 * PI * I * k / N) * X[k + N/2];
//    }
//}
//
//void fft(int* x, double complex* X, unsigned int N) {
//    fft_radix2(x, X, N, 1);
//}

/* Fast Fourier Transform
 * Cooley-Tukey algorithm with 2-radix DFT
 */

#include <complex.h>
#include <math.h>
#include <stdint.h>

#define PI 3.14159265358979323846

void fft_radix2(float* x, float* X_Re, float* X_Im, unsigned int N, unsigned int s) {

    // At the lowest level pass through (delta T=0 means no phase).
    if (N == 1) {
        //X[0] = x[0];
        X_Re[0] = x[0];
        X_Im[0] = x[0]; //Cuestionable
        return;
    }

    uint16_t k;
    float t_Re;
    float t_Im;
    uint16_t N_2 = N/2;
    uint16_t _2s = 2*s;

    // Cooley-Tukey: recursively split in two, then combine beneath.
    fft_radix2(x, X_Re, X_Im, N_2, _2s);
    fft_radix2(x+s, X_Re + N_2, X_Im + N_2, N_2, _2s);

    float _2pi_N = 2*PI/N;
    float sinw, cosw;
    float cosw_XRe_plus_sinw_XIm, cosw_XIm_minus_sinw_XRe;

    for (k = 0; k < N_2; k++) {

        cosw = cos(_2pi_N*k);
        sinw = sin(_2pi_N*k);
        cosw_XRe_plus_sinw_XIm  = cosw*X_Re[k + N_2] + sinw*X_Im[k + N_2];
        cosw_XIm_minus_sinw_XRe = cosw*X_Im[k + N_2] - sinw*X_Re[k + N_2];

        t_Re = X_Re[k];
        t_Im = X_Im[k];

        X_Re[k]       = t_Re + (cosw_XRe_plus_sinw_XIm);
        X_Im[k]       = t_Im + (cosw_XIm_minus_sinw_XRe);
        
        X_Re[k + N_2] = t_Re - (cosw_XRe_plus_sinw_XIm);
        X_Im[k + N_2] = t_Im - (cosw_XIm_minus_sinw_XRe);
    }
}

void fft_slow(float* x, double complex* X, unsigned int N) {
    unsigned int n, k;

    // Iterate through, allowing X_K = sum_N of the complex frequencies.
    for (k = 0; k < N; k++) {
        for (n = 0; n < N; n++) {
            X[k] += x[n] * cexp(-2 * PI * I * n * k / N);
        }
    }
}

void fftComplex2Real(float* X_Re, float* X_Im, float* x, int N){
    int i;

    for(i=0; i<N; i++){
        x[i] = X_Re[i]*X_Re[i] +  X_Im[i]*X_Im[i];   // Dividir entre el ancho de BIN
    }
}

void fft(float* x, float* X_Re, float* X_Im, unsigned int N) {
    fft_radix2(x, X_Re, X_Im, N, 1);
}


//void fftComplex2Real(double complex* X, float* x, int N){
//    int i;
//
//    for(i=0; i<N; i++){
//        x[i] = pow(creal(X[i]), 2) + pow(cimag(X[i]), 2);
//    }
//}
//
//void fft(float* x, double complex* X, unsigned int N) {
//    fft_slow(x, X, N);
//}
