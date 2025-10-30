#ifndef __livi_utils_arguments_h__
#define __livi_utils_arguments_h__

namespace livi {

void argumentsInit(int argc, char *argv[]);
int argumentsGetArgc();
char **argumentsGetargv();

}  // namespace livi

#endif
