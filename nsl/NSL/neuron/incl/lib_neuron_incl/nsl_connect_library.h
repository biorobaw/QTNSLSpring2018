//
//	nsl_connect_library.h
//

// neuron<-weight<-neuron

extern void NSLconnect(nsl_neuron_vector&,
	nsl_neuron_vector&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_vector&,
	nsl_neuron_vector&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_vector&,nsl_neuron_data&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_vector&,nsl_neuron_data&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_neuron_data&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_neuron_vector&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_neuron_vector&,nsl_num_data&,int);

// neuron<-weight<-layer

extern void NSLconnect(nsl_neuron_vector&,
	nsl_num_vector&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_vector&,
	nsl_num_vector&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_vector&,nsl_num_data&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_vector&,nsl_num_data&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_num_data&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_num_vector&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_num_vector&,nsl_num_data&,int);

// neuron<-neuron

extern void NSLconnect(nsl_neuron_vector&,nsl_neuron_vector&,int);
extern void NSLconnect(nsl_neuron_vector&,nsl_neuron_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_neuron_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_neuron_vector&,int);

// neuron<-layer

extern void NSLconnect(nsl_neuron_vector&,nsl_num_vector&,int);
extern void NSLconnect(nsl_neuron_vector&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_num_data&,int);
extern void NSLconnect(nsl_neuron_data&,nsl_num_vector&,int);



