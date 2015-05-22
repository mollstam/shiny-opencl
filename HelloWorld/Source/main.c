//
//  main.c
//  OpenCL_HelloWorld
//
//  Created by Tobias on 22/05/15.
//  Copyright (c) 2015 Tobias. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#include <unistd.h>
#else
#include <CL/cl.h>
#endif

#include "err_code.h"

int main(int argc, char** argv)
{
    cl_int err;
 
    cl_uint num_platforms;
    err = clGetPlatformIDs(0, NULL, &num_platforms);
    check_error(err, "Finding platforms");
    
    if (num_platforms == 0)
    {
        printf("Found 0 platforms, exiting...\n");
        return EXIT_FAILURE;
    }
    
    printf("Found %d platform(s).\n", num_platforms);
    
    // getting some more info about platforms
    
    cl_platform_id platform[num_platforms];
    err = clGetPlatformIDs(num_platforms, platform, NULL);
    check_error(err, "Getting platforms");
    
    for (int i = 0; i < num_platforms; ++i)
    {
        cl_char string[10240] = {0};
        
        err = clGetPlatformInfo(platform[i], CL_PLATFORM_NAME, sizeof(string), &string, NULL);
        check_error(err, "Getting platform name");
        printf("*  %s", string);
        
        // list devices
        
        cl_uint num_devices;
        err = clGetDeviceIDs(platform[i], CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
        check_error(err, "Finding devices");
        
        printf(" -- %d device(s):\n", num_devices);
        
        cl_device_id device[num_devices];
        err = clGetDeviceIDs(platform[i], CL_DEVICE_TYPE_ALL, num_devices, device, NULL);
        check_error(err, "Getting devices");
        
        for (int j = 0; j < num_devices; ++j)
        {
            err = clGetDeviceInfo(device[j], CL_DEVICE_NAME, sizeof(string), &string, NULL);
            check_error(err, "Getting device name");
            printf("   *  %s\n", string);
        }
    }
    
    return EXIT_SUCCESS;
}
