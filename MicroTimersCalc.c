
#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main(){
    uint64_t PSC, ARR; 
    uint64_t psc_timer_bits, arr_timer_bits;
    double timer_freq, desired_freq, real_freq;
    
    uint64_t min_PSC, min_ARR;
	uint64_t valid_combinations = 0;
    double min_freq_error;
    double best_freq;
    double current_freq_error;
	
    printf("Timer frequency without prescaling: \n");
    scanf("%lf",&timer_freq);
    
    printf("Prescaling bit resolution (PSC): \n");
    scanf("%ld",&psc_timer_bits);
    
    printf("Count-based period bit resolution (ARR): \n");
    scanf("%ld",&arr_timer_bits);
    
    printf("Desired frequency: \n");
    scanf("%lf",&desired_freq);
    
    for(PSC = 1 ; PSC < pow(2, psc_timer_bits) ; PSC++){
		ARR = (timer_freq / PSC) / desired_freq;
		real_freq = 1 / (ARR * (PSC / timer_freq));
            
		if(ARR < pow(2 , arr_timer_bits)){
			current_freq_error = real_freq - desired_freq;
			
			if((current_freq_error < min_freq_error &&  current_freq_error >= 0) || valid_combinations == 0){
				min_ARR = ARR;
				min_PSC = PSC;
				best_freq = real_freq;
				min_freq_error = current_freq_error;
			}        
			
			valid_combinations++;
		}
    }
	
    if(valid_combinations != 0){
		printf("\nPSC: %ld ARR: %ld Real Freq: %0.4lf\n",min_PSC,min_ARR,best_freq);
	}
	else{
		printf("\nNo ARR and PSC values exist for the desired frequency, change the CLK frequency\n");
	}
}



