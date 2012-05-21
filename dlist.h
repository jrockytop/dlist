/*
 * Copyright (c) 1995 Jason W. Cox.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Jason W. Cox.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Double Linked List
 *
 * File: dlist.h
 *
 * Author: Jason Cox, derived from Plank's dlist
 *
 * Description: This is a library of functions to manipulate a double linked
 *              list.
 *
 */

/*
 * $Log: dlist.h,v $
 * Revision 1.1.1.1  2007/03/25 20:27:05  j
 * Dlist added to repository
 *
 * Revision 1.1.1.1  2006/05/13 00:56:38  j
 * jvalue - initial checkin
 *
 * Revision 1.1  1996/02/25  21:39:38  cox
 * Initial revision
 *
 * Revision 1.1  1995/11/13  01:05:07  cox
 * Initial revision
 *
 */

#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>

typedef struct dlist {
    void *item;
    struct dlist *next;
    struct dlist *prev;
} *Dlist;


Dlist dl_create(void);

void dl_insert_a(Dlist, void *);
void dl_insert_b(Dlist, void *);

void dl_delete(Dlist);
void dl_delete_item(Dlist);

void dl_clear(Dlist);
void dl_clear_all(Dlist);

void dl_destroy(Dlist);
void dl_destroy_all(Dlist);

int dl_length(Dlist);

#define dl_last(n) (n->prev)
#define dl_first(n) (n->next)
#define dl_next(n) (n->next)
#define dl_prev(n) (n->prev)
#define dl_empty(n) (n->next == n)
#define dl_nil(n) (n)

#define dl_traverse(ptr, list) \
  for ((ptr) = dl_first(list); (ptr) != dl_nil(list); (ptr) = dl_next(ptr))

#define dl_rtraverse(ptr, list) \
  for ((ptr) = dl_last(list); (ptr) != dl_nil(list); (ptr) = dl_prev(ptr))

#endif
