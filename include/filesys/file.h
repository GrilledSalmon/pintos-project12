#ifndef FILESYS_FILE_H
#define FILESYS_FILE_H

#include "filesys/off_t.h"

struct inode;

/***GrilledSalmon***/
#define FDTSIZE 128

struct fd_key_value {
	int user_fd;		// 유저가 사용하는 fd값
	int kernel_fd;		// 커널이 사용하는 fd값
};

/* Opening and closing files. */
struct file *file_open (struct inode *);
struct file *file_reopen (struct file *);
struct file *file_duplicate (struct file *file);
void file_close (struct file *);
struct inode *file_get_inode (struct file *);

/* Reading and writing. */
off_t file_read (struct file *, void *, off_t);
off_t file_read_at (struct file *, void *, off_t size, off_t start);
off_t file_write (struct file *, const void *, off_t);
off_t file_write_at (struct file *, const void *, off_t size, off_t start);

/* Preventing writes. */
void file_deny_write (struct file *);
void file_allow_write (struct file *);

/* File position. */
void file_seek (struct file *, off_t);
off_t file_tell (struct file *);
off_t file_length (struct file *);

/*** Jack ***/
/* Lock for file */
void file_lock_acquire (struct file *f);
void file_lock_release (struct file *f);

/*** GrilledSalmon ***/
void file_dup_cnt_up(struct file *f);
void file_dup_cnt_down(struct file *f);
int16_t file_get_dup_cnt(struct file *f);

#endif /* filesys/file.h */
