/*
 * tiny_debug.h
 *
 *  Created on: Dec 25, 2024
 *      Author: amiro
 */

#ifndef TINY_DEBUG_TINY_DEBUG_H_
#define TINY_DEBUG_TINY_DEBUG_H_

#define ENABLE_GLOBAL_DEBUG

#include <stdio.h>
//#include <string.h>

#define NEWLINE			"\r\n"

#if defined(ENABLE_GLOBAL_DEBUG) || defined(DEBUG_THIS_FILE)

//	#define FILENAME_PATH_OMMITED 		(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

	#define PLACE(x)                    do{x} while(0)
	#define PRINT(...)                  printf(__VA_ARGS__)

	#define DEBUG_FUNC(string, ...)          PRINT(string, ##__VA_ARGS__)
	#define DEBUG_LN(...)               	{   DEBUG_FUNC(__VA_ARGS__);\
												DEBUG_FUNC(NEWLINE); }

	#define DEBUG_PRINT_HEADER(HEADER)               DEBUG_FUNC(" + [" #HEADER "] \t: ")
	#define DEBUG_PRINT_MSG(HEADER, MSG, ...)        DEBUG_FUNC(" + [" #HEADER "] \t: " MSG NEWLINE, ##__VA_ARGS__)


	#define DEBUG_OK(...)       DEBUG_PRINT_MSG(OK, __VA_ARGS__)
	#define DEBUG_WARNING(...)  DEBUG_PRINT_MSG(WARN, __VA_ARGS__)
	#define DEBUG_TRACE()       DEBUG_FUNC(" + [TRACE] \t: File : %s :: Function : %s() :: Line : %d" NEWLINE, __FILE__, __func__, __LINE__)
	#define DEBUG_ERROR(...)    	PLACE(\
										DEBUG_PRINT_HEADER(ERROR);     \
										DEBUG_LN(__VA_ARGS__);   \
										DEBUG_TRACE();  \
										)
	#define DEBUG_EXCEPTION(...)    PLACE(\
										DEBUG_PRINT_HEADER(EXCEPTION);     \
										DEBUG_LN(__VA_ARGS__);   \
										DEBUG_TRACE();  \
										)


#else
	#define PLACE(x)
	#define PRINT(...)
	#define DEBUG_FUNC(string, ...)
	#define DEBUG_LN(...)
	#define DEBUG_PRINT_HEADER(HEADER)
	#define DEBUG_PRINT_MSG(HEADER, MSG, ...)
	#define DEBUG_OK(...)
	#define DEBUG_ERROR(...)
	#define DEBUG_WARNING(...)
	#define DEBUG_TRACE()
	#define DEBUG_EXCEPTION(...)
#endif /* defined(ENABLE_GLOBAL_DEBUG) || defined(DEBUG_THIS_FILE) */

#endif /* TINY_DEBUG_TINY_DEBUG_H_ */
