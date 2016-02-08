/*
 * psc.h
 *
 *  Created on: Feb 7, 2016
 *      Author: agy
 */

#ifndef PSC_H_
#define PSC_H_

#include <cstdlib>
#include <papi.h>
#include <iostream>
#include <string.h>

// Select your counters here!
#define NUM_OF_ANALYSIS 500
#define NUM_OF_COUNTERS 2

int selected_counters [NUM_OF_COUNTERS] = {PAPI_L1_DCA ,PAPI_L1_ICA};
std::string cntr_name [NUM_OF_COUNTERS] = {"PAPI_L1_DCA" ,"PAPI_L1_ICA"};
// Counter selection ends here!

long long counter_values[NUM_OF_ANALYSIS][NUM_OF_COUNTERS]; //Results are stored here!

void start_PAPI(){
	int ret;
	if ((ret = PAPI_start_counters(selected_counters, NUM_OF_COUNTERS)) != PAPI_OK) {
	   std::cerr << "PAPI failed to start counters: " << PAPI_strerror(ret) << std::endl;
	   exit(EXIT_FAILURE);
	}
}

void read_PAPI(int iter){
	int ret;
	long long temp_values [NUM_OF_COUNTERS];
	if ((ret = PAPI_read_counters(temp_values, NUM_OF_COUNTERS)) != PAPI_OK) {
		std::cerr << "PAPI failed to read counters: " << PAPI_strerror(ret) << std::endl;
	   exit(EXIT_FAILURE);
	}
	//for (int i = 0 ; i < NUM_OF_COUNTERS ; i++)
		//std::cout << "-- " << temp_values[i] << std::endl;
	std::copy(temp_values,temp_values + NUM_OF_COUNTERS, counter_values[iter]);
}

void report_PAPI(int iter){
	if (iter == -1){
		for (int i = 0 ; i < NUM_OF_ANALYSIS ; i++) {
			for(int j = 0 ; j < NUM_OF_COUNTERS ; j++) {
				std::cout << cntr_name[j] << "[" << i << "] : " << counter_values[i][j] << " ";
			}
			std::cout << std::endl;

		}
	}
	else {
		for(int j = 0 ; j < NUM_OF_COUNTERS ; j++) {
			std::cout << "[PAPI] " << cntr_name[j] << " : " << counter_values[iter][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif /* PSC_H_ */
