// ##########################################
// 
//   Author  -   Collin Thornton
//   Email   -   collin.thornton@okstate.edu
//   Alg     -   Golf Cart Physical Constants
//   Date    -   07-28-2020
//      
//
// ##########################################


#ifndef VEHICLE_PARAMETERS_H
#define VEHICLE_PARAMETERS_H


namespace low_level {
    namespace nucleo {
        /** Wheelbase (m) */
        const float L = 1.69;

        /** Gear ratio from steering wheel to front wheels 
         * @todo EXPERIMENTALLY DETERMINE
        */
        const float LAMBDA = 0.5;     

        /** Mass (kg) */
        // const float M = ___;
    }
}

#endif // VEHICLE_PARAMETERS_H