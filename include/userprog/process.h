#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_create_initd (const char *file_name);
tid_t process_fork (const char *name, struct intr_frame *if_);
int process_exec (void *f_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (struct thread *next);
void argument_stack (char **parse, int count, struct intr_frame *_if);        /*** Grilled Salmon ***/

#endif /* userprog/process.h */

#ifdef USERPROG // debugging genie

/*** team 8 : phase 2 ***/
int process_add_file(struct file *f);
struct file *process_get_file(int user_fd);
void process_close_file(int user_fd);

/*** team 8 : phase 3 ***/
void remove_child_process(struct thread *cp);
struct thread *get_child_process (int pid);

struct fd_key_value *find_fd_key_value(int user_fd); /*** GrilledSalmon ***/

#endif //userprog // debugging genie
