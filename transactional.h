/*
 * transactional.h
 *
 *  Created on: 30 kwi 2016
 *      Author: zabkiewi
 */

#ifndef TRANSACTIONAL_H_
#define TRANSACTIONAL_H_

#include "typedef.h"
#include "list.h"

typedef struct _transaction {
	uint32 tid;		/* unique id */
	LIST * opr;		/* list of operations */
} Transaction;

#endif /* TRANSACTIONAL_H_ */
