/* SCCS  %W%---%E%--%U% */
//
//	nsl_num_0.h
//

//template<class NslNumType>
#ifndef _NSL_NUM_0_H
#define _NSL_NUM_0_H
#include "nsl_data_layer.h"
class nsl_num_0 : public nsl_data_layer
{
protected:
	NslNumType v; 
public:
	nsl_num_0(const NslNumType val = 0,int=0,int=1,int = 1); // 0,1
	nsl_num_0(const char*, nsl_public* = 0,int=0,int=1,int=1);
	nsl_num_0(const char*, const NslNumType, nsl_public* = 0,
		int=0,int=1,int=1);
//	nsl_num_0(const nsl_num_0&,int=0,int=1,int=1); // 0,1
	nsl_num_0(const NslFloat0&,int=0,int=1,int=1); // 0,1
/*	nsl_num_0(const NslDinFloat0&,int=0,int=1,int=1); // 0,1
	nsl_num_0(const NslDinDouble0&,int=0,int=1,int=1); // 0,1
	nsl_num_0(const NslDinInt0&,int=0,int=1,int=1); // 0,1
	nsl_num_0(const NslDoutFloat0&,int=0,int=1,int=1); // 0,1
	nsl_num_0(const NslDoutDouble0&,int=0,int=1,int=1); // 0,1
	nsl_num_0(const NslDoutInt0&,int=0,int=1,int=1); // 0,1
*/	~nsl_num_0(void);

	void initialize(const char*, nsl_public* = 0,int=0,int=1,int=1);

	int	init_num_data();
	int memAlloc();

	NslNumType get_data() 	const { return v; }
	NslNumType get_value() 	const { return v; }
	NslNumType getValue() 	const { return v; }
	NslNumType& elem() { return v; } 	

//	void	set_value(const NslNumType);
	void	set_value(float);
	void	set_value(double);
	void	set_value(int);

// add
	nsl_num_0 operator+() const;
	nsl_num_0 operator+(const nsl_num_0&) const;
	nsl_num_0 operator+(const NslNumType) const;

// assignment
	NslNumType 	operator=(const NslFloat0&);
//	NslNumType 	operator=(const nsl_din_num_0&);
//	NslNumType 	operator=(const nsl_dout_num_0&);
	NslNumType 	operator=(const float);
	NslNumType 	operator=(const double);
	NslNumType 	operator=(const int);

// print

	virtual int	nslPrint() const;
	int	print_num_data() const;
	virtual int	nslStatus() const;
	int	print_num_data_status() const;

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

	int 	write_num_data(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_num_data(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);
};
#endif
