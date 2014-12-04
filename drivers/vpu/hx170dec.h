/*------------------------------------------------------------------------------
--                                                                            --
--       This software is confidential and proprietary and may be used        --
--        only as expressly authorized by a licensing agreement from          --
--                                                                            --
--                            Hantro Products Oy.                             --
--                                                                            --
--                   (C) COPYRIGHT 2006 HANTRO PRODUCTS OY                    --
--                            ALL RIGHTS RESERVED                             --
--                                                                            --
--                 The entire notice above must be reproduced                 --
--                  on all copies and should not be removed.                  --
--                                                                            --
--------------------------------------------------------------------------------
--
--  Abstract : x170 Decoder device driver (kernel module)
--
--------------------------------------------------------------------------------
--
--  Version control information, please leave untouched.
--
--  $RCSfile: hx170dec.h,v $
--  $Date: 2008-05-06 07:20:39 $
--  $Revision: 1.3 $
--
------------------------------------------------------------------------------*/

#ifndef _HX170DEC_H_
#define _HX170DEC_H_
#include <linux/ioctl.h>    /* needed for the _IOW etc stuff used later */
/*
 * Macros to help debugging
 */
#undef PDEBUG   /* undef it, just in case */
#ifdef HX170DEC_DEBUG
#  ifdef __KERNEL__
    /* This one if debugging is on, and kernel space */
#    define PDEBUG(fmt, args...) printk( KERN_INFO "hx170dec: " fmt, ## args)
#  else
    /* This one for user space */
#    define PDEBUG(fmt, args...) printf(__FILE__ ":%d: " fmt, __LINE__ , ## args)
#  endif
#else
#  define PDEBUG(fmt, args...)  /* not debugging: nothing */
#endif

/*
 * Ioctl definitions
 */

/* Use 'k' as magic number */
#define HX170DEC_IOC_MAGIC  'k'
/*
 * S means "Set" through a ptr,
 * T means "Tell" directly with the argument value
 * G means "Get": reply by setting through a pointer
 * Q means "Query": response is on the return value
 * X means "eXchange": G and S atomically
 * H means "sHift": T and Q atomically
 */

#define HX170DEC_PP_INSTANCE       _IO(HX170DEC_IOC_MAGIC, 1)   /* the client is pp instance */
#define HX170DEC_HW_PERFORMANCE    _IO(HX170DEC_IOC_MAGIC, 2)   /* decode/pp time for HW performance */
#define HX170DEC_IOCGHWOFFSET      _IOR(HX170DEC_IOC_MAGIC,  3, unsigned long *)
#define HX170DEC_IOCGHWIOSIZE      _IOR(HX170DEC_IOC_MAGIC,  4, unsigned int *)

#define HX170DEC_IOC_CLI           _IO(HX170DEC_IOC_MAGIC,  5)
#define HX170DEC_IOC_STI           _IO(HX170DEC_IOC_MAGIC,  6)
#define HX170DEC_dec_read           _IOR(HX170DEC_IOC_MAGIC,  7, unsigned int *)
#define HX170DEC_dec_write           _IOW(HX170DEC_IOC_MAGIC,  8, unsigned int *)
#define HX170DEC_pp_read           _IOR(HX170DEC_IOC_MAGIC,  9, unsigned int *)
#define HX170DEC_pp_write           _IOW(HX170DEC_IOC_MAGIC,  10, unsigned int *)
//#define HX170DEC_pp_pid_write           _IOW(HX170DEC_IOC_MAGIC,  11, unsigned int *)
#define HX170DEC_IOC_MAXNR 10


#endif /* !_HX170DEC_H_ */
