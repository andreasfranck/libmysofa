/*

   Copyright 2016 Christian Hoene, Symonics GmbH

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#ifndef MYSOFA_H_INCLUDED
#define MYSOFA_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


	/** attributes */
struct MYSOFA_ATTRIBUTE {
	    struct MYSOFA_ATTRIBUTE *next;
	    char *name;
	    char *value;
};

struct MYSOFA_ARRAY {
    double *values;
    int elements;
    struct MYSOFA_ATTRIBUTE *attributes;
};

/*
 * The HRTF structure data types
 */
struct MYSOFA_HRTF {

	/** number of HRTF filters stores here */
	/** size of each filter */
	/** number of different elevation degrees */
	/* array of elevation degrees. 0 is front. PI is up, -PI is down. Size of array is <elevations>. Values are sorted incrementally. */
	/** array of increasing number of azimuth numbers per elevation. Starts with zero, second value is the number of azimuth for the first elevation, third value is the number of azimuths for the first and second elevation   */
	/** array of azimuth degrees. -PI/2 is left, 0 is front, PI/2 is right. Size is <filters>. For each elevation, the azimuth values are sorted incrementally. */
	/** attributes */

/* Dimensions defined in AES69 
  M Number of measurements; must be integer greater than zero.
  R Number of receivers; must be integer greater than zero.
  E Number of emitters; must be integer greater than zero.
  N Number of data samples describing one measurement; must be integer greater than zero.
  S Number of characters in a string; must be integer greater than zero.
  I 1 Singleton dimension, defines a scalar value.
  C 3 Coordinate triplet, always three; the coordinate type defines the meaning of this dimension.
*/
    unsigned I,C,R,E,N,M;
    
    struct MYSOFA_ARRAY ListenerPosition;
        
    struct MYSOFA_ARRAY ReceiverPosition;
    
    struct MYSOFA_ARRAY SourcePosition;
    
    struct MYSOFA_ARRAY EmitterPosition;

    struct MYSOFA_ARRAY ListenerUp;
    
    struct MYSOFA_ARRAY ListenerView;
    
    	/** array of filter coefficients. Sizes are filters*filter_length. */
    struct MYSOFA_ARRAY DataIR;

    /** the sampling rate used in this structure */
    struct MYSOFA_ARRAY DataSamplingRate;
    
    	/** array of min-phase delays. Sizes are filters */
    struct MYSOFA_ARRAY DataDelay;
        
        /** general file attributes */    
	struct MYSOFA_ATTRIBUTE *attributes;
};

enum {
	MYSOFA_OK = 0,
	MYSOFA_INVALID_FORMAT = 10000,
	MYSOFA_UNSUPPORTED_FORMAT,
	MYSOFA_INTERNAL_ERROR,
	MYSOFA_NO_MEMORY,
	MYSOFA_READ_ERROR
};

struct MYSOFA_HRTF* mysofa_load(char *filename, int *err);
void mysofa_free(struct MYSOFA_HRTF *hrtf);

#ifdef __cplusplus
}
#endif
#endif

