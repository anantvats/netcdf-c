/* This is part of the netCDF package. Copyright 2017 University
   Corporation for Atmospheric Research/Unidata See COPYRIGHT file for
   conditions of use. See www.unidata.ucar.edu for more info.

   Test proper elatefill return when fillvalue is assigned outside of
   the initial define.

   Contributed by wkliao, see the following for more information:

   * https://github.com/Unidata/netcdf-c/issues/388
   * https://github.com/Unidata/netcdf-c/pull/389
*/

#include "config.h"
#include <nc_tests.h>
#include <stdio.h>
#include <netcdf.h>

#define FILE_NAME "tst_global_fillval.nc"

#define ERR {if(err!=NC_NOERR){printf("Error at line %d: %s\n",__LINE__,nc_strerror(err)); toterrs++; break;}}
int
main(int argc, char **argv)
{
    int i, ncid, cmode, err, fillv=9;
    int toterrs = 0;
    int formats[5]={0,
                    NC_64BIT_OFFSET,
                    NC_64BIT_DATA,
                    NC_NETCDF4,
                    NC_CLASSIC_MODEL | NC_NETCDF4};
    char *formatnames[5]={"CDF-1", "CDF-2", "CDF-5", "NETCDF4", "CLASSIC_MODEL"};

    for (i=0; i<5; i++) {
        cmode = NC_CLOBBER | formats[i];
        err = nc_create(FILE_NAME, cmode, &ncid); ERR

        err = nc_put_att_int(ncid, NC_GLOBAL, "_FillValue", NC_INT, 1, &fillv);
        if (err != NC_EGLOBAL) {
          toterrs++;
          printf("%13s Error at line %d: expecting NC_EINVAL but got %d\n",
                   formatnames[i],__LINE__,err);
        }
        err = nc_close(ncid); ERR;

    }
    printf("Total errors: %d\n",toterrs);
    return toterrs;
}
