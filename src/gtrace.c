
// Radokhleb Valery
// Version 1.0
// ██████╗ ██████╗ ██╗  ██╗        ████████╗██████╗  █████╗  █████╗ ███████╗        ████████╗ █████╗  █████╗ ██╗
// ██╔══██╗██╔══██╗██║  ██║        ╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝        ╚══██╔══╝██╔══██╗██╔══██╗██║
// ██████╔╝██║  ██║███████║           ██║   ██████╔╝███████║██║  ╚═╝█████╗             ██║   ██║  ██║██║  ██║██║
// ██╔══██╗██║  ██║██╔══██║           ██║   ██╔══██╗██╔══██║██║  ██╗██╔══╝             ██║   ██║  ██║██║  ██║██║
// ██║  ██║██████╔╝██║  ██║           ██║   ██║  ██║██║  ██║╚█████╔╝███████╗           ██║   ╚█████╔╝╚█████╔╝███████╗
// ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝           ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚══════╝           ╚═╝    ╚════╝  ╚════╝ ╚══════╝


#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "gtrace.h"



//ORD-2
VOID Launch(_COM command) {
	system(command);
}

//ORD-3
PVOID Malloc_handler(size_t size) {

	void* ptr = malloc(size);
	if (ptr != NULL)
	{
		return ptr;
	}
	else {
		perror("[ERROR] Error in heap (malloc)");
		exit(1);
	}
}

//ORD-4
VOID Usage(
	int argc, 
	_COM command
) 
{
	if (argc < 2) {
		system(command);
		exit(2);
	}
}

VOID Add_arg(
	char* buffer, 
	size_t size_of_buffer, 
	_COM arg) 
{
	if (arg == NULL) {
		printf("[ERROR] NULL in argument. Exit");
		exit(3);	
	}

	strcat_s(buffer ,size_of_buffer, " ");
	strcat_s(buffer ,size_of_buffer, arg);
	strcat_s(buffer ,size_of_buffer, " ");
}


//ORD-1
int main(int argc, char* argv[]) {
	
	// Local
	_LOCAL;

	// Start args
	_PATH path;
	size_t total_args_length;
	size_t result_length;
	size_t total_length_of_start;
	_COM help_alert;
	_COM start_command;
	_PATH main_script;
	_PATH module_name_to_remove;
	_COM help_command;
	_COM init_py;
	_PATH help_file;
	_PATH help_path;
	RESULT result;


	// Make space to paths
	path = (char*)Malloc_handler(MAX_PATH);
	help_path = (char*)Malloc_handler(MAX_PATH);

	// Make src directory (for working in CMD by PATH variable)
	GetModuleFileName(NULL, path, MAX_PATH);
	module_name_to_remove = strrchr(path, '\\');
	*module_name_to_remove = '\0';



	// Start variables (init start python files)
	// +++++++++++++++++++++++++++++++++++++++++
	help_command = "--help"; 
	main_script = "\\gtrace.py";
	init_py = "python";
	help_file = "\\performance\\help.txt";
	// +++++++++++++++++++++++++++++++++++++++++
	
	// Total length of start command (Without src directory)
	total_length_of_start = strlen(init_py) + strlen(main_script) + strlen(help_command) + MAX_PATH;

	//Buffer for help alert, include src directory
	help_alert = (char*)Malloc_handler(total_length_of_start);

	// Build help file path
	snprintf(
		help_path, 
		MAX_PATH + strlen(help_file), 
		"%s%s", 
		path, 
		help_file);

	// Build help alert command
	snprintf(
		help_alert, 
		MAX_PATH + total_length_of_start + strlen(help_path), 
		"%s %s%s %s %s", 
		init_py, 
		path, 
		main_script, 
		help_path, 
		help_command
	);

	
	

	// Check args; If above 2, show help alert
	Usage(argc, help_alert);
	free(help_alert);

	
	start_command = Malloc_handler(total_length_of_start);
	snprintf(start_command, total_length_of_start, "%s %s%s ", init_py, path, main_script);
	free(path);

	total_args_length = 0;
	// Make length of args
	for (int i = 1; i < argc; i++) {
		total_args_length += strlen(argv[i]) + 1;  
	}

	// Length of result
	result_length = total_length_of_start + total_args_length + 1;


	result = (char*)Malloc_handler(result_length);
	
	// Make start
	strcpy_s(result, result_length, start_command);
	free(start_command);

	Add_arg(result, result_length, help_path);

	for (int i = 1; i < argc; i++) {
		// Add user args without name of the file
		strcat_s(result, result_length, argv[i]);
		if (i < argc - 1) {
			strcat_s(result, result_length , " ");
		}
	}

	//Free
	Launch(result);
	free(result);
	return 0;

}
