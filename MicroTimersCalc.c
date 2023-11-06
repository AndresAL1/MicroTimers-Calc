
#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(){
    uint64_t PSC, ARR; 
    uint64_t psc_timer_bits, arr_timer_bits;
    double timer_freq, desired_freq, real_freq;
    
    uint64_t min_PSC, min_ARR;
    double min_freq_error = 99999999;
    double best_freq;
    
    printf("Frecuencia del timer sin preescalar: \n");
    scanf("%lf",&timer_freq);
    
    printf("Resolucion en bits del timer (PSC): \n");
    scanf("%ld",&psc_timer_bits);
    
    printf("Resolucion en bits del timer (ARR): \n");
    scanf("%ld",&arr_timer_bits);
    
    printf("Frecuencia deseada: \n");
    scanf("%lf",&desired_freq);
    
    for(PSC = 1 ; PSC < pow(2, psc_timer_bits) ; PSC++){
            ARR = (timer_freq / PSC) / desired_freq;
            real_freq = 1 / (ARR * (PSC / timer_freq));
            
            if(ARR < pow(2 , arr_timer_bits)){
                double current_freq_error = real_freq - desired_freq;
                if(current_freq_error < min_freq_error &&  current_freq_error >= 0){
                    min_ARR = ARR;
                    min_PSC = PSC;
                    best_freq = real_freq;
		            min_freq_error = current_freq_error;
                }    
                //printf("PSC: %d ARR: %d Real Freq: %lf\n",PSC,ARR,real_freq);    
            }
            
            //printf("PSC: %d ARR: %d Real Freq: %lf\n",PSC,ARR,real_freq);
    }
    
    printf("\nPSC: %ld ARR: %ld Real Freq: %lf\n",min_PSC,min_ARR,best_freq);
}



