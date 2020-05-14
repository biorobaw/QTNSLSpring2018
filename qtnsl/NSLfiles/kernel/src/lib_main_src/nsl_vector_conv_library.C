/* SCCS  @(#)nsl_vector_conv_library.C	1.1---95/08/13--20:48:20 */
//
//	nsl_vector_conv_library.C
//

#include "nsl.h"
#include "nsl_num_2.h"
#include "nsl_num_1.h"
#include "nsl_num_0.h"

//typedef nsl_num_2 nsl_num_2;
//typedef nsl_num_0 nsl_num_0;
//typedef nsl_num_1 nsl_num_1;

nsl_num_1 operator*(const nsl_num_1& a,const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator*\n";
	cout << "// (vector) " << a.get_name() << " * (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int saimax = a.get_imax();
	int sbimax = b.get_imax();

	int simax = saimax + sbimax - 1;

	nsl_num_1 c(sbimax);
	nsl_num_1 d(simax);

	d.put_sector(b,saimax/2); 

	for (int i = 0; i < sbimax; i++)
	   {	
		num_type val = 0;
		for (int m = 0; m < saimax; m++)
			val = val + a[m] * d[i+m];
		c[i] = val;
	   }

	return c;
}
nsl_num_1 operator*(const nsl_num_1& a,const num_type b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator*\n";
	cout << "// (vector) " << a.get_name() << " * (num_type) ";
	cout << b << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] * b;

	return c;
}
nsl_num_1 operator*(const num_type a, const nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator*\n";
	cout << "// (num_typer) " << a << " * (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a * b[i];

	return c;
}
nsl_num_1 operator*(const nsl_num_1& a,const nsl_num_0& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator*\n";
	cout << "// (vector) " << a.get_name() << " * (data) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] * b.get_data();

	return c;
}
nsl_num_1 operator*(const nsl_num_0& a,const  nsl_num_1& b)
{
#ifdef NSL_DEBUG
	cout << "// nsl_num_1  operator*\n";
	cout << "// (data) " << a.get_name() << " * (vector) ";
	cout << b.get_name() << ";\n";
	cout.flush();
#endif

	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a.get_data() * b[i];

	return c;
}

// zero-edge vector convolution

nsl_num_1 NSLconv_zero(const nsl_num_1& a,const nsl_num_1& b)
{
	int saimax = a.get_imax();
	int sbimax = b.get_imax();

	int simax = saimax + sbimax - 1;

	nsl_num_1 c(sbimax);
	nsl_num_1 d(simax);

	d.put_sector(b,saimax/2); 

	for (int i = 0; i < sbimax; i++)
	   {	
		num_type val = 0;
		for (int m = 0; m < saimax; m++)
			val = val + a[m] * d[i+m];
		c[i] = val;
	   }
	return c;
}
nsl_num_1 NSLconv_zero(const nsl_num_1& a,const num_type b)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] * b;

	return c;
}
nsl_num_1 NSLconv_zero(const num_type a, const nsl_num_1& b)
{
	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a * b[i];

	return c;
}
nsl_num_1 NSLconv_zero(const nsl_num_1& a,const nsl_num_0& b)
{
	int aimax = a.get_imax();

	nsl_num_1 c(aimax);

	for (int i = 0; i < aimax; i++)
		c[i] = a[i] * b.get_data();

	return c;
}
nsl_num_1 NSLconv_zero(const nsl_num_0& a,const  nsl_num_1& b)
{
	int bimax = b.get_imax();

	nsl_num_1 c(bimax);

	for (int i = 0; i < bimax; i++)
		c[i] = a.get_data() * b[i];

	return c;
}

// wrap around convolution

nsl_num_1 NSLconv_wrap(const nsl_num_1& a,const nsl_num_1& b)
{
      	int saimax = a.get_imax();
      	int sbimax = b.get_imax();

	int sm = saimax/2;

      	int simax = saimax + sbimax - 1;

      	nsl_num_1 c(sbimax);
      	nsl_num_1 d(simax);

      	d.put_sector(b,saimax/2); 

	int i,m;

      	for (i = sm-1; i >= 0; i--)
	   d[i] = b[(i-sm+sbimax)%sbimax];
      	for (i = sm+sbimax; i < simax; i++)
	   d[i] = b[(i-sm)%sbimax];

     	for (i = 0; i < sbimax; i++)
        {    
              num_type val = 0;
              for (m = 0; m < saimax; m++)
                      val = val + a[m] * d[i+m];
              c[i] = val;
        }

        return c;
}

// copy boundary convolution

nsl_num_1 NSLconv_copy(const nsl_num_1& a,const nsl_num_1& b)
{
      	int saimax = a.get_imax();
      	int sbimax = b.get_imax();

	int sm = saimax/2;

      	int simax = saimax + sbimax - 1;

      	nsl_num_1 c(sbimax);
      	nsl_num_1 d(simax);

      	d.put_sector(b,saimax/2); 

	int i,m;

      	for (i = sm-1; i >= 0; i--)
	   d[i] = b[0];
      	for (i = sm+sbimax; i < simax; i++)
	   d[i] = b[sbimax-1];

      	for (i = 0; i < sbimax; i++)
        {    
              num_type val = 0;
              for (m = 0; m < saimax; m++)
                      val = val + a[m] * d[i+m];
              c[i] = val;
        }

        return c;
}

