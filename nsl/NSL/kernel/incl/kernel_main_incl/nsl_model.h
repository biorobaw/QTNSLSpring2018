/* SCCS  @(#)nsl_model.h	1.1---95/08/13--23:37:18 */
//
// 	nsl_model.h
//

#ifndef _NSL_MODEL_H
#define _NSL_MODEL_H
#include "nsl_public.h"
#include "nsl_module.h"
#include "nsl_num_0.h"
class nsl_model : public nsl_public
{
protected:
	NslFloat0 simDelta;		// simulation time step
	NslFloat0 trainDelta;	// train time step

	NslFloat0 simSysTime;	// simulation absolute time
	NslFloat0 trainSysTime;	// train absolute time

	NslFloat0 simCurrentTime;	// simulation current time
	int simCurrentTimeStep; // simulation current time step
	NslFloat0 trainCurrentTime;	// train current time
	int trainCurrentTimeStep; // train current time step

	NslFloat0 simEndTime;	// simulation end time
	int simEndTimeStep;	// simulation end time step
	NslFloat0 trainEndTime;	// train end time
	int trainEndTimeStep;	// train end time step

	NslFloat0 simEpochSteps;	// epoch steps (int)
	NslFloat0 simEpochStep;	// epoch step (int)

	NslFloat0 trainEpochSteps;	// epoch steps (int)
	NslFloat0 trainEpochStep;	// epoch step (int)

	NslFloat0 trainAccumCurrentTime; // train accumulated current time
	int trainAccumCurrentTimeStep; // train accumulated current time step

	int function_total; 	// total number of run functions
	nsl_list* function_list; 	// pointer to all nsl functions

	int model_total; 	// total number of sub models
	nsl_list* model_list; 	// pointer to all sub models

	nsl_diff_manager* DIFFM;	// diff information

	int sim_fg; // 0 - sim, 1 - train

public:
		nsl_model(const char*,nsl_model* = 0,int=1);
		nsl_model();
		~nsl_model();

	int init_model(const char*,nsl_model* = 0,int=0);

// get
	float getSimDelta() { return simDelta.get_value(); }
	float getSimSysTime() { return simSysTime.get_value(); }
	float getSimEndTime() { return simEndTime.get_value(); }
	int getSimEndTimeStep() { return simEndTimeStep; }
	float getSimTime() { return simCurrentTime.get_value(); }
	float getSimCurrentTime() { return simCurrentTime.get_value(); }
	int getSimTimeStep() { return simCurrentTimeStep; }
	int getSimCurrentTimeStep() { return simCurrentTimeStep; }

	float getTrainDelta() { return trainDelta.get_value(); }
	float getTrainSysTime() { return trainSysTime.get_value(); }
	float getTrainEndTime() { return trainEndTime.get_value(); }
	int getTrainEndTimeStep() { return trainEndTimeStep; }
	float getTrainTime() { return trainCurrentTime.get_value(); }
	float getTrainCurrentTime() { return trainCurrentTime.get_value(); }
	int getTrainCurrentTimeStep() { return trainCurrentTimeStep; }
	int getTrainTimeStep() { return trainCurrentTimeStep; }

	float getTrainAccumTime() { return trainAccumCurrentTime.get_value(); }
	float getTrainAccumCurrentTime() { return trainAccumCurrentTime.get_value(); }
	int getTrainAccumCurrentTimeStep() { return trainAccumCurrentTimeStep; }

	int getSimEpochSteps() { return (int) simEpochSteps.get_value(); }
	int getSimEpochStep() { return (int) simEpochStep.get_value(); }

	int getTrainEpochSteps() { return (int) trainEpochSteps.get_value(); }
	int getTrainEpochStep() { return (int) trainEpochStep.get_value(); }

	nsl_diff_manager* get_diff_manager() { return DIFFM; }

	int getSimFg() { return sim_fg; }

// set
	void 	setSimDelta(float f) { simDelta = f; }
	void	setSimSysTime(float f) { simSysTime = f; }
	void 	setSimTime(float);
	void 	setSimTime(int); // check out this
	void 	setSimEndTime(float);
	void 	setSimCurrentTime(float f) { setSimTime(f); }
	void 	setSimTimeStep(int);
	void 	setSimEndTimeStep(int);
	void 	setSimCurrentTimeStep(int f) { setSimTime(f); }

	void 	setTrainDelta(float f) { trainDelta = f; }
	void	setTrainSysTime(float f) { trainSysTime = f; }
	void 	setTrainTime(float);
	void 	setTrainTime(int); // check out this
	void 	setTrainEndTime(float);
	void 	setTrainCurrentTime(float f) { setTrainTime(f); }
	void 	setTrainTimeStep(int);
	void 	setTrainEndTimeStep(int);
	void 	setTrainCurrentTimeStep(int f) { setTrainTime(f); }

	void 	setTrainAccumTime(float);
	void 	setTrainAccumCurrentTimeStep(int f) { setTrainAccumTime(f); }
	void 	setTrainAccumCurrentTime(float f) { setTrainAccumTime(f); }

	void 	setSimEpochSteps(int i) { simEpochSteps = i; }
	void 	setSimEpochStep(int i) { simEpochStep = i; }

	void 	setTrainEpochSteps(int i) { trainEpochSteps = i; }
	void 	setTrainEpochStep(int i) { trainEpochStep = i; }

	void 	set_diff_manager(nsl_diff_manager* d) { DIFFM = d; }

	void 	setSimFg(int i) { sim_fg = i; }

// reset time
	void resetSimTime();
	void resetTrainTime();
// increment time 
	void incrSimTime();
	void incrSimSysTime() { simSysTime = simSysTime + 1; }
	void incrTrainTime();
	void incrTrainSysTime() { trainSysTime = trainSysTime + 1; }

// functions
	int get_function_total() { return function_total; }
	nsl_list* get_function_list() { return function_list; }

	int	add_function(nsl_function*);

	nsl_function*	get_function();		// get first function
	nsl_function*	get_function(const char*);// name search
	nsl_function*	get_function(const int);	// index search

// models
	int get_model_total() { return model_total; }
	nsl_list* get_model_list() { return model_list; }

	int	add_model(nsl_model*);

	nsl_model*	get_model();			// get first function
	nsl_model*	get_model(const char*);		// name search
	nsl_model*	get_model(const int);		// index search

	virtual nsl_model* makeInstance();

// AW98 AslSchema methods
	void updateBuffers(void) { }
	void memAlloc(void) { }

	virtual void initSys(void) { }
	virtual void callFromConstructorTop(void) { }
	virtual void makeInst(void) { }
	virtual void callFromConstructorBottom(void) { }
	virtual void makeConn(void) { }
	virtual void initModule(void) { }
	virtual void initTrainEpochs(void) { }
	virtual void initTrain(void) { }
	virtual void simTrain(void) { }
	virtual void endTrain(void) { }
	virtual void endTrainEpochs(void) { }
	virtual void initRunEpochs(void) { }
	virtual void initRun(void) { }
	virtual void simRun(void) { }
	virtual void endRun(void) { }
	virtual void endRunEpochs(void) { }
	virtual void endModule(void) { }
	virtual void endSys(void) { }

// Old methods
	virtual int init();

	virtual int run();
	int run(const int,const int);
	int run(const float,const float);

// header for output data file
	void file_header(std::ostream&);

// print
	virtual int 	print(std::ostream&) const;
	int 	print_model(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_model_status(std::ostream&) const;

	virtual int 	print_all(std::ostream&) const;
	int 	print_model_all(std::ostream&) const;
	virtual int 	print_all_status(std::ostream&) const;
	int 	print_model_all_status(std::ostream&) const;

	int 	write_model(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_model(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	write_model(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_model(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);
};
#endif

