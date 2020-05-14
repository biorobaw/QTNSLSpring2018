/* SCCS  @(#)nsl_matrix_conv_library.C	1.1---95/08/13--20:48:15 */
//
//	nsl_matrix_conv_library.C
//

#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

// matrix convolution

nsl_num_2 operator*(const nsl_num_2& a,const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (matrix) " << a.get_name() << " * (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int simax = saimax + sbimax - 1;
	int sjmax = sajmax + sbjmax - 1;

	nsl_num_2 c(sbimax,sbjmax);
	nsl_num_2 d(simax,sjmax);

	d.put_sector(b,saimax/2,sajmax/2); 

	for (int i = 0; i < sbimax; i++)
	   for (int j = 0; j < sbjmax; j++)
	   {	
		num_type val = (num_type) 0;
		for (int m = 0; m < saimax; m++)
		   for (int n = 0; n < sajmax; n++)
			val = val + a[m][n] * d[i+m][j+n];
		c[i][j] = val;
	   }

	return c;
}

nsl_num_2 operator*(const nsl_num_1& a,const nsl_num_2& b) // row,col vector
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (vector) " << a.get_name() << " * (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int saimax = a.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int vec_type;
	int simax;
	int m;
	num_type val;
	val = 0;

	nsl_num_2 c(sbimax,sbjmax);

	if ((vec_type = a.get_vec_type()) == 0)
	{
		simax = saimax + sbjmax - 1;
		nsl_num_2 d(sbimax,simax);
		d.put_sector(b,0,saimax/2); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;	
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i][j+m];
			c[i][j] = val;
		   }
	}
	else
	{
		simax = saimax + sbimax - 1;
		nsl_num_2 d(simax,sbjmax);
		d.put_sector(b,saimax/2,0); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i+m][j];
			c[i][j] = val;
		   }
	}

	return c;
}
nsl_num_2 operator*(const nsl_num_2& b,const nsl_num_1& a) // same as previous
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (matrix) " << a.get_name() << " * (vector) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int saimax = a.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int vec_type;
	int simax;
	int m;
	num_type val;
	val = 0;

	nsl_num_2 c(sbimax,sbjmax);

	if ((vec_type = a.get_vec_type()) == 0)
	{
		simax = saimax + sbjmax - 1;
		nsl_num_2 d(sbimax,simax);

		d.put_sector(b,0,saimax/2); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;	
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i][j+m];
			c[i][j] = val;
		   }
	}
	else
	{
		simax = saimax + sbimax - 1;
		nsl_num_2 d(simax,sbjmax);

		d.put_sector(b,saimax/2,0); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i+m][j];
			c[i][j] = val;
		   }
	}

	return c;
}
nsl_num_2 operator*(const nsl_num_2& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (matrix) " << a.get_name() << " * (data) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b.get_data();

	return c;
}
nsl_num_2 operator*(const nsl_num_0& a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (data) " << a.get_name() << " * (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a.get_data() * b[i][j];

	return c;
}
nsl_num_2 operator*(const nsl_num_2& a,const num_type b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (matrix) " << a.get_name() << " * (num_type) ";
        cout << b << ";\n";
        cout.flush();
#endif

	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b;

	return c;
}
nsl_num_2 operator*(const num_type a, const nsl_num_2& b)
{
#ifdef NSL_DEBUG
        cout << "// nsl_num_2 operator*\n";
        cout << "// (num_type) " << a << " * (matrix) ";
        cout << b.get_name() << ";\n";
        cout.flush();
#endif

	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a * b[i][j];

	return c;
}

// zero edge matrix convolution 

nsl_num_2 NSLconv_zero(const nsl_num_2& a,const nsl_num_2& b)
{
	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int simax = saimax + sbimax - 1;
	int sjmax = sajmax + sbjmax - 1;

	nsl_num_2 c(sbimax,sbjmax);
	nsl_num_2 d(simax,sjmax);

	d.put_sector(b,saimax/2,sajmax/2); 

	for (int i = 0; i < sbimax; i++)
	   for (int j = 0; j < sbjmax; j++)
	   {	
		num_type val = (num_type) 0;
		for (int m = 0; m < saimax; m++)
		   for (int n = 0; n < sajmax; n++)
			val = val + a[m][n] * d[i+m][j+n];
		c[i][j] = val;
	   }

	return c;
}
nsl_num_2 NSLconv_zero(const nsl_num_1& a,
	const nsl_num_2& b) // row,col vector
{
	int saimax = a.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int vec_type;
	int simax;
	int m;
	num_type val = 0;

	nsl_num_2 c(sbimax,sbjmax);

	if ((vec_type = a.get_vec_type()) == 0)
	{
		simax = saimax + sbjmax - 1;
		nsl_num_2 d(sbimax,simax);
		d.put_sector(b,0,saimax/2); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;	
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i][j+m];
			c[i][j] = val;
		   }
	}
	else
	{
		simax = saimax + sbimax - 1;
		nsl_num_2 d(simax,sbjmax);
		d.put_sector(b,saimax/2,0); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i+m][j];
			c[i][j] = val;
		   }
	}

	return c;
}
nsl_num_2 NSLconv_zero(const nsl_num_2& b,
	const nsl_num_1& a) // same as previous
{
	int saimax = a.get_imax();
	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int vec_type;
	int simax;
	int m;
	num_type val = 0;

	nsl_num_2 c(sbimax,sbjmax);

	if ((vec_type = a.get_vec_type()) == 0)
	{
		simax = saimax + sbjmax - 1;
		nsl_num_2 d(sbimax,simax);
		d.put_sector(b,0,saimax/2); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;	
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i][j+m];
			c[i][j] = val;
		   }
	}
	else
	{
		simax = saimax + sbimax - 1;
		nsl_num_2 d(simax,sbjmax);
		d.put_sector(b,saimax/2,0); 

		for (int i = 0; i < sbimax; i++)
		   for (int j = 0; j < sbjmax; j++)
		   {	
			val = 0;
			for (m = 0; m < saimax; m++)
			    val = val + a[m] * d[i+m][j];
			c[i][j] = val;
		   }
	}

	return c;
}
nsl_num_2 NSLconv_zero(const nsl_num_2& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b.get_data();

	return c;
}
nsl_num_2 NSLconv_zero(const nsl_num_0& a, const nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a.get_data() * b[i][j];

	return c;
}
nsl_num_2 NSLconv_zero(const nsl_num_2& a,const num_type b)
{
	int aimax = a.get_imax();
	int ajmax = a.get_jmax();

	nsl_num_2 c(aimax,ajmax);

	for (int i = 0; i < aimax; i++)
	   for (int j = 0; j < ajmax; j++)
		c[i][j] = a[i][j] * b;

	return c;
}
nsl_num_2 NSLconv_zero(const num_type a,const  nsl_num_2& b)
{
	int bimax = b.get_imax();
	int bjmax = b.get_jmax();

	nsl_num_2 c(bimax,bjmax);

	for (int i = 0; i < bimax; i++)
	   for (int j = 0; j < bjmax; j++)
		c[i][j] = a * b[i][j];

	return c;
}

// wrap around convolution

nsl_num_2 NSLconv_wrap(const nsl_num_2& a,const nsl_num_2& b)
{
      	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
      	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int smi = saimax/2;
	int smj = sajmax/2;

 	int simax = saimax + sbimax - 1;
	int sjmax = sajmax + sbjmax - 1;

      	nsl_num_2 c(sbimax,sbjmax);
      	nsl_num_2 d(simax,sjmax);

      	d.put_sector(b,saimax/2,sajmax/2); 

	int i,j;

      	for (i = smi-1; i >= 0; i--)
    	   for (j = smj; j < sbjmax+smj; j++)
 	   	d[i][j] = b[(i-smi+sbimax)%sbimax][j-smj];
      	for (i = smi+sbimax; i < simax; i++)
    	   for (j = smj; j < sbjmax+smj; j++)
	   	d[i][j] = b[(i-smi)%sbimax][j-smj];

    	for (j = smj-1; j >= 0; j--)
    	   for (i = smi; i < sbimax+smi; i++)
	   	d[i][j] = b[i-smi][(j-smj+sbjmax)%sbjmax];
     	for (j = smj+sbjmax; j < sjmax; j++)
    	   for (i = smi; i < sbimax+smi; i++)
	   	d[i][j] = b[i-smi][(j-smj)%sbjmax];

      	for (i = 0; i < sbimax; i++)
      	    for (j = 0; j < sbjmax; j++)
            {    
              	num_type val = (num_type) 0;
              	for (int m = 0; m < saimax; m++)
		   for (int n = 0; n < sajmax; n++)
			val = val + a[m][n] * d[i+m][j+n];
		c[i][j] = val;
            }
  
        return c;
}
nsl_num_2 NSLconv_copy(const nsl_num_2& a,const nsl_num_2& b)
{
      	int saimax = a.get_imax();
	int sajmax = a.get_jmax();
      	int sbimax = b.get_imax();
	int sbjmax = b.get_jmax();

	int smi = saimax/2;
	int smj = sajmax/2;

 	int simax = saimax + sbimax - 1;
	int sjmax = sajmax + sbjmax - 1;

      	nsl_num_2 c(sbimax,sbjmax);
      	nsl_num_2 d(simax,sjmax);

      	d.put_sector(b,saimax/2,sajmax/2); 

	int i,j;

      	for (i = smi-1; i >= 0; i--)
    	   for (j = smj; j < sbjmax+smj; j++)
 	   	d[i][j] = b[0][j-smj];
      	for (i = smi+sbimax; i < simax; i++)
    	   for (j = smj; j < sbjmax+smj; j++)
	   	d[i][j] = b[sbimax-1][j-smj];

    	for (j = smj-1; j >= 0; j--)
    	   for (i = smi; i < sbimax+smi; i++)
	   	d[i][j] = b[i-smi][0];
     	for (j = smj+sbjmax; j < sjmax; j++)
    	   for (i = smi; i < sbimax+smi; i++)
	   	d[i][j] = b[i-smi][sbjmax-1];

      	for (i = 0; i < sbimax; i++)
      	    for (j = 0; j < sbjmax; j++)
            {    
              	num_type val = (num_type) 0;
              	for (int m = 0; m < saimax; m++)
		   for (int n = 0; n < sajmax; n++)
			val = val + a[m][n] * d[i+m][j+n];
		c[i][j] = val;
            }
  
        return c;
}
