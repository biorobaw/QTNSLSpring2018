/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_data.h
//

#ifndef _NSL_NUM_DATA_H
#define _NSL_NUM_DATA_H
#include "nsl_data_layer.h"
class nsl_num_data : public nsl_data_layer
{
protected:
	float v;
public:
		nsl_num_data(const num_type=0,int = 1);
		nsl_num_data(const char*,const num_type=0,int=0,int=1);
		nsl_num_data(const nsl_num_data&,int = 1);

		~nsl_num_data();

	int	init_num_data();

// get value
	num_type get_data() 	const { return v; }
	num_type get_value() 	const { return v; }
	num_type& elem() { return v; } 	

// set value
	num_type	set_value(const int);
	num_type	set_value(const float);
	num_type	set_value(const double);

// assignment
	num_type 	operator=(const nsl_num_data&);
	num_type 	operator=(const double);
	num_type 	operator=(const float);
	num_type 	operator=(const int);

	/**!!! added operators !!!!***/
	//-bn7
	nsl_num_data operator*(num_type a)
	{
		return nsl_num_data(a*v,1);
	}

	nsl_num_data operator-(nsl_num_data a)
	{
		return nsl_num_data(a.get_value() - v,1);
	}

	bool operator==(const int a)
	{
		if(get_data() == a)
			return 1;
		else
			return 0;
	}

	bool operator>(nsl_num_data &rhs)
	{
		return (v > rhs.v);
	}
	//----------------------------


// print
	virtual int	print(std::ostream&) const;
	int	print_num_data(std::ostream&) const;
	virtual int	print_status(std::ostream&) const;
	int	print_num_data_status(std::ostream&) const;

	int 	reset_num_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};

/* 3.0 version
class nsl_num_data : public nsl_data_layer
{
protected:
	num_type v;
public:
		nsl_num_data(const num_type=0,int = 1);
		nsl_num_data(const char*,const num_type=0,int=0,int=1);
		nsl_num_data(const nsl_num_data&,int = 1);

		~nsl_num_data();

	int	init_num_data();

// get value
	num_type get_data() 	const { return v; }
	num_type get_value() 	const { return v; }
	num_type& elem() { return v; }

// set value
	num_type	set_value(const int);
	num_type	set_value(const float);
	num_type	set_value(const double);

// assignment
	num_type 	operator=(const nsl_num_data&);
	num_type 	operator=(const double);
	num_type 	operator=(const float);
	num_type 	operator=(const int);

// print
	virtual int	print(ostream&) const;
	int	print_num_data(ostream&) const;
	virtual int	print_status(ostream&) const;
	int	print_num_data_status(ostream&) const;

	int 	reset_num_data(nsl_buffer* = 0);
	virtual int 	reset(nsl_buffer* = 0);

	int 	write_num_data(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_num_data(nsl_buffer&);
	virtual int 	read(nsl_buffer&);
};
 * */
#endif
