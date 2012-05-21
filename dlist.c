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
 * File: dlist.c
 *
 * Author: Jason Cox, derived from Plank's dlist
 *
 * Description: This is a library of functions to manipulate a double linked
 *              list.
 *
 */

/*
 * $Log: dlist.c,v $
 * Revision 1.1.1.1  2007/03/25 20:27:05  j
 * Dlist added to repository
 *
 * Revision 1.2  2006/05/15 06:43:51  j
 * Magic formula works now.
 *
 * Revision 1.1.1.1  2006/05/13 00:56:38  j
 * jvalue - initial checkin
 *
 * Revision 1.1  1996/02/25  21:38:57  cox
 * Initial revision
 *
 * Revision 1.2  1995/11/20  01:36:25  cox
 * Fixed the dl_insert_a(), dl_insert_b() mixup.
 *
 * Revision 1.1  1995/11/13  01:02:59  cox
 * Initial revision
 *
 */

#include <dlist.h>
#include <stdlib.h>

//#ident "$Id: dlist.c,v 1.1.1.1 2007/03/25 20:27:05 j Exp $";

/*
 * dl_create
 *
 * Description: Create a Dlist sentinel node and return it.
 *
 */
Dlist dl_create(void)
{
    Dlist l;

    l = (Dlist) malloc(sizeof(struct dlist));
	if (!l) {
		perror("malloc");
		return NULL;
	}
	
    l->item = NULL;
    l->next = l->prev = l;

    return l;
}


/*
 * dl_insert_b
 *
 * Description: Insert an item before the given Dlist node.
 *
 */
void dl_insert_b(Dlist l, void *item)
{
    Dlist node;

    node = (Dlist) malloc(sizeof(struct dlist));
	if (!node) {
		perror("malloc");
		return;
	}

    node->item = item;
    node->next = l;
    node->prev = l->prev;
    l->prev->next = node;
    l->prev = node;
}


/*
 * dl_insert_a
 *
 * Description: Insert an item after the given Dlist node.
 *
 */
void dl_insert_a(Dlist l, void *item)
{
    Dlist node;

    node = (Dlist) malloc(sizeof(struct dlist));
	if (!node) {
		perror("malloc");
		return;
	}
	
    node->item = item;
    node->next = l->next;
    node->prev = l;
    l->next->prev = node;
    l->next = node;
}


/*
 * dl_delete
 *
 * Description: Deletes and frees a Dlist node from a Dlist.
 *
 */
void dl_delete(Dlist node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}


/*
 * dl_delete_item
 *
 * Description: Deletes and frees a Dlist node from a Dlist and also
 *              frees the item in the node too.
 *
 */
void dl_delete_item(Dlist node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node->item);
    free(node);
}


/*
 * dl_clear
 *
 * Description: Deletes and frees all nodes in the given Dlist except the
 *              sentinel node.  The Dlist will be empty and can be reused.
 *
 */
void dl_clear(Dlist l)
{
    Dlist tmp = l->next, next;
    
    while (tmp != l) {
		next = tmp->next;
		free(tmp);
		tmp = next;
    }
    l->next = l->prev = l;
}


/*
 * dl_clear_all
 *
 * Description: This function is like the dl_clear function except that
 *              it also calls free on all of the items in the list too.
 *
 */
void dl_clear_all(Dlist l)
{
    Dlist tmp = l->next, next;
    
    while (tmp != l) {
		next = tmp->next;
		free(tmp->item);
		free(tmp);
		tmp = next;
    }
    l->next = l->prev = l;
}


/*
 * dl_destroy
 *
 * Description: Deletes and frees all nodes in the given Dlist except the
 *              sentinel node.  The Dlist will be freed and cannot be reused.
 *
 */
void dl_destroy(Dlist l)
{
    Dlist tmp = l->next, next;
    
    while (tmp != l) {
		next = tmp->next;
		free(tmp);
		tmp = next;
    }
    free(l);
}


/*
 * dl_destroy_all
 *
 * Description: This function is like the dl_destroy function except that
 *              it also calls free on all of the items in the list too.
 *
 */
void dl_destroy_all(Dlist l)
{
    Dlist tmp = l->next, next;
    
    while (tmp != l) {
		next = tmp->next;
		free(tmp->item);
		free(tmp);
		tmp = next;
    }
    free(l);
}


/*
 * dl_length
 *
 * Description: This function returns the length of the given Dlist.
 *
 */
int dl_length(Dlist l)
{
    Dlist tmp;
    int c = 0;

    for (tmp=l->next; tmp != l; tmp=tmp->next)
		c++;
    return c;
}
