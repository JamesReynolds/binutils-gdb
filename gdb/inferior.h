/* Variables that describe the inferior process running under GDB:
   Where it is, why it stopped, and how to step it.
   Copyright (C) 1986 Free Software Foundation, Inc.

GDB is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY.  No author or distributor accepts responsibility to anyone
for the consequences of using it or for whether it serves any
particular purpose or works at all, unless he says so in writing.
Refer to the GDB General Public License for full details.

Everyone is granted permission to copy, modify and redistribute GDB,
but only under the conditions described in the GDB General Public
License.  A copy of this license is supposed to have been given to you
along with GDB so you can know your rights and responsibilities.  It
should be in a file named COPYING.  Among other things, the copyright
notice and this notice must be preserved on all copies.

In other words, go ahead and share GDB, but don't try to stop
anyone else from sharing it farther.  Help stamp out software hoarding!
*/

/*
 * Structure in which to save the status of the inferior.  Save
 * through "save_inferior_status", restore through
 * "restore_inferior_status".
 * This pair of routines should be called around any transfer of
 * control to the inferior which you don't want showing up in your
 * control variables.
 */
struct inferior_status {
  int pc_changed;
  int stop_signal;
  int stop_pc;
  int stop_frame_address;
  int stop_breakpoint;
  int stop_step;
  int stop_stack_dummy;
  int stopped_by_random_signal;
  int trap_expected;
  CORE_ADDR step_range_start;
  CORE_ADDR step_range_end;
  FRAME_ADDR step_frame_address;
  int step_over_calls;
  CORE_ADDR step_resume_break_address;
  int stop_after_trap;
  int stop_after_attach;
  FRAME_ADDR selected_frame_address;
  int selected_level;
  struct command_line *breakpoint_commands;
  char stop_registers[REGISTER_BYTES];
  int restore_stack_info;
};

void save_inferior_status (), restore_inferior_status ();

/* File name for default use for standard in/out in the inferior.  */

extern char *inferior_io_terminal;

/* Pid of our debugged inferior, or 0 if no inferior now.  */

extern int inferior_pid;

/* Nonzero if debugging a remote machine via a serial link or ethernet.  */

extern int remote_debugging;

/* Last signal that the inferior received (why it stopped).  */

extern int stop_signal;

/* Address at which inferior stopped.  */

extern CORE_ADDR stop_pc;

/* Stack frame when program stopped.  */

extern FRAME_ADDR stop_frame_address;

/* Number of breakpoint it stopped at, or 0 if none.  */

extern int stop_breakpoint;

/* Nonzero if stopped due to a step command.  */

extern int stop_step;

/* Nonzero if stopped due to completion of a stack dummy routine.  */

extern int stop_stack_dummy;

/* Nonzero if program stopped due to a random (unexpected) signal in
   inferior process.  */

extern int stopped_by_random_signal;

/* Range to single step within.
   If this is nonzero, respond to a single-step signal
   by continuing to step if the pc is in this range.  */

extern CORE_ADDR step_range_start; /* Inclusive */
extern CORE_ADDR step_range_end; /* Exclusive */

/* Stack frame address as of when stepping command was issued.
   This is how we know when we step into a subroutine call,
   and how to set the frame for the breakpoint used to step out.  */

extern FRAME_ADDR step_frame_address;

/* 1 means step over all subroutine calls.
   -1 means step over calls to undebuggable functions.  */

extern int step_over_calls;

/* If stepping, nonzero means step count is > 1
   so don't print frame next time inferior stops
   if it stops due to stepping.  */

extern int step_multi;

/* Save register contents here when about to pop a stack dummy frame.  */

extern char stop_registers[REGISTER_BYTES];

/* Nonzero if pc has been changed by the debugger
   since the inferior stopped.  */

extern int pc_changed;


long read_memory_integer ();
