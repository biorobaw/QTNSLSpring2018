//
// 	nsl_system.h
//

#ifndef _NSL_SYSTEM_H
#define _NSL_SYSTEM_H
#include "nsl_public.h"
#include "nsl_str_data.h"
#include "nsl_num_0.h"
#ifndef _NSL_SET
class nsl_module;
class nsl_str_data;
class nsl_num_0;
#endif
class nsl_system : public nsl_public
{
protected:
	NslStr0 model;

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

	NslFloat0 simAccumCurrentTime; // sim accumulated current time
	int simAccumCurrentTimeStep; // sim accumulated current time step
	NslFloat0 trainAccumCurrentTime; // train accumulated current time
	int trainAccumCurrentTimeStep; // train accumulated current time step

	NslFloat0 simEpochSteps;	// epoch steps (int)
	NslFloat0 simEpochStep;	// epoch step (int)

	NslFloat0 trainEpochSteps;	// epoch steps (int)
	NslFloat0 trainEpochStep;	// epoch step (int)

// current pointer
	on_off_enum xsystem_fg;		// ON - Window interface
//	nsl_interpreter* INTERPRETER;	// interpreter
 
	int model_total; 		// total number of models
	nsl_list* model_list; 		// pointer to all models

	int model_application_total; 	// total number of application models
	nsl_list* model_application_list; // pointer to all application models

	int proc_total; 		// total number of system procs
	nsl_list* proc_list; 		// pointer to all system procs

	int diff_method_total; 		// total number of diff methods
	nsl_list* diff_method_list; 	// pointer to all diff methods

	int diff_model_total; 		// total number of diff models
	nsl_list* diff_model_list; 	// pointer to all diff models

	nsl_diff_manager* DIFFM;	// diff information

	int thresh_lib_total; 		// total number of thresh libraries
	nsl_list* thresh_lib_list; 	// pointer to all thresh libraries

// i/o files
	nsl_string nsl_dir;		// nsl system directory
 
	int file_type_total; 		// total number of file types
	nsl_list* file_type_list;   	// pointer to file list types

	nsl_file_manager* fm;		// file manager

// cmds
	nsl_cmd_system* sys;		// cmd_system root

 // system
	int* argc_ptr;
	char** argv_ptr;
	
public:
		nsl_system();
		virtual ~nsl_system();

// get
	const char* getAppModel() { return model.get_value(); }

	float getSimDelta() { return simDelta.get_value(); }
	float getSimSysTime() { return simSysTime.get_value(); }
	float getSimEndTime() { return simEndTime.get_value(); }
	int getSimEndTimeStep() { return simEndTimeStep; }
	float getSimTime() { return simCurrentTime.get_value(); }
	float getSimCurrentTime() { return simCurrentTime.get_value(); }
	int getSimTimeStep() { return simCurrentTimeStep; }
	int getSimCurrentTimeStep() { return simCurrentTimeStep; }

	float getSimAccumTime() { return simAccumCurrentTime.get_value(); }
	float getSimAccumCurrentTime() { return simAccumCurrentTime.get_value(); }
	int getSimAccumCurrentTimeStep() { return simAccumCurrentTimeStep; }

	float getTrainDelta() { return trainDelta.get_value(); }
	float getTrainSysTime() { return trainSysTime.get_value(); }
	float getTrainEndTime() { return trainEndTime.get_value(); }
	int getTrainEndTimeStep() { return trainEndTimeStep; }
	float getTrainTime() { return trainCurrentTime.get_value(); }
	float getTrainCurrentTime() { return trainCurrentTime.get_value(); }
	int getTrainTimeStep() { return trainCurrentTimeStep; }
	int getTrainCurrentTimeStep() { return trainCurrentTimeStep; }

	float getTrainAccumTime() { return trainAccumCurrentTime.get_value(); }
	float getTrainAccumCurrentTime() { return trainAccumCurrentTime.get_value(); }
	int getTrainAccumCurrentTimeStep() { return trainAccumCurrentTimeStep; }

	int getSimEpochSteps() { return (int) simEpochSteps.get_value(); }
	int getSimEpochStep() { return (int) simEpochStep.get_value(); }

	int getTrainEpochSteps() { return (int) trainEpochSteps.get_value(); }
	int getTrainEpochStep() { return (int) trainEpochStep.get_value(); }

// set
	void 	setAppModel(char* str) { model = str; }

	void 	setSimDelta(float f) { simDelta = f; }
	void	setSimSysTime(float f) { simSysTime = f; }
	void 	setSimTime(float);
	void 	setSimTime(int); // check out this
	void 	setSimEndTime(float);
	void 	setSimCurrentTime(float f) { setSimTime(f); }
	void 	setSimTimeStep(int);
	void 	setSimEndTimeStep(int);
	void 	setSimCurrentTimeStep(int f) { setSimTime(f); }

	void 	setSimAccumTime(float);
	void 	setSimAccumCurrentTimeStep(int f) { setSimAccumTime(f); }
	void 	setSimAccumCurrentTime(float f) { setSimAccumTime(f); }

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

	void setSimEpochSteps(int i) { simEpochSteps = i; }
	void setSimEpochStep(int i) { simEpochStep = i; }

	void setTrainEpochSteps(int i) { trainEpochSteps = i; }
	void setTrainEpochStep(int i) { trainEpochStep = i; }

// reset time
	void resetSimTime();
	void resetTrainTime();
// increment time 
	void incrSimTime();
	void incrSimSysTime() { simSysTime = simSysTime + 1; }
	void incrTrainTime();
	void incrTrainSysTime() { trainSysTime = trainSysTime + 1; }

	void		set_xsystem_fg(on_off_enum fg) { xsystem_fg = fg; }
	on_off_enum	get_xsystem_fg() { return xsystem_fg; }

// model
	int		add_model(nsl_model*);
	nsl_model*	get_model() { return (nsl_model*) get_ptr(); }
	nsl_model*	get_model(const int);		// index search
/* AW99
	int 	get_model_total() { return model_total; }
	nsl_list* get_model_list() { return model_list; }
	nsl_model*	get_model(const char*);		// name search
	void		set_model(nsl_model* m) { set_ptr((nsl_base*)m); }
*/
	int addApplicationModel(nsl_model*);
	nsl_model* getApplicationModel(const char*);

	int makeModelInstance();

// AW98 AslSchema methods
	virtual int initTrain(void) { return 1; }
	virtual int simTrain(void) { return 1; }
	virtual int endTrain(void) { return 1; }
	virtual int initRun(void) { return 1; }
	virtual int simRun(void) { return 1; }
	virtual int endRun(void) { return 1; }
	virtual int initSys(void) { return 1; }
	virtual int endSys(void) { return 1; }
	virtual int initModule(void) { return 1; }
	virtual int endModule(void) { return 1; }

// procedure
	int 	get_proc_total() { return proc_total; }
	nsl_list* get_proc_list() { return proc_list; }

	int		insert_proc(nsl_function*);
	int		add_proc(nsl_function*);
	nsl_function*	get_proc(const char*);		// name search
	nsl_function*	get_proc(const int);		// index search

	int 		init();
	int 		init_proc();

// diff method
	int 	get_diff_method_total() { return diff_method_total; }
	nsl_list* get_diff_method_list() { return diff_method_list; }

	int		add_diff_method(nsl_diff_method*);
	nsl_diff_method*	get_diff_method(const char*);

// diff model
	int 	get_diff_model_total() { return diff_model_total; }
	nsl_list* get_diff_model_list() { return diff_model_list; }

	int		add_diff_model(nsl_diff*);
	nsl_diff*	get_diff_model(const char*); // nsl_diff_model

// diff manager
	nsl_diff_manager* get_diff_manager() { return DIFFM; }
	void 	set_diff_manager(nsl_diff_manager* d) { DIFFM = d; }

// thresh
	int 	get_thresh_lib_total() { return thresh_lib_total; }
	nsl_list* get_thresh_lib_list() { return thresh_lib_list; }

	int		add_thresh_lib(nsl_thresh_library*);
	nsl_thresh_library*	get_thresh_lib(const char*);

// interpreter
//	void		set_interpreter(nsl_interpreter* m) { NSL = m; }
//	nsl_interpreter* get_interpreter() { return NSL; } 

// i/o file
	char* 	get_nsl_dir() { return nsl_dir; }
	void 	set_nsl_dir(const char* str) { strcpy(nsl_dir,str); }
 
	int 	get_file_type_total() { return file_type_total; }
	nsl_list* get_file_type_list() { return file_type_list; }

	int		add_file_type(nsl_file*);
	nsl_file*	get_file_type(const char*);	// name search
	nsl_file*	get_file_type(const int);	// index search

	nsl_file_manager* get_file_manager() { return fm; }

// cmds
	nsl_cmd_system* get_cmd_system() { return sys; }
	void set_cmd_system(nsl_cmd_system* s) { sys = s; }

// system
	void set_argc_ptr(int* ptr) { argc_ptr = ptr; }
	int* get_argc_ptr() { return argc_ptr; }
	void set_argv_ptr(char** ptr) { argv_ptr = ptr; }
	char** get_argv_ptr() { return argv_ptr; }

// print status
	int	init_system();

	int write_model(fstream*,nsl_model*);
	void print_layers(fstream*,nsl_model*);
	void print_models(fstream*,nsl_model*);

//inicio cambios EGR
	void print_models_variables(nsl_model* model);
	void print_layers_variables(nsl_model* model);
//fin cambios EGR

	virtual int 	print(std::ostream&) const;
	int 	print_system(std::ostream&) const;
	virtual int 	print_status(std::ostream&) const;
	int 	print_system_status(std::ostream&) const;

	virtual int 	print_all(std::ostream&) const;
	int 	print_system_all(std::ostream&) const;
	virtual int 	print_all_status(std::ostream&) const;
	int 	print_system_all_status(std::ostream&) const;

	int 	write_system(nsl_buffer&);
	virtual int 	write(nsl_buffer&);
	int 	read_system(nsl_buffer&);
	virtual int 	read(nsl_buffer&);

	int 	write_system(nsl_char_buf&);
	virtual int 	write(nsl_char_buf&);
	int 	read_system(nsl_char_buf&);
	virtual int 	read(nsl_char_buf&);
};
#endif
