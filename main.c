/*
 * main.c
 *
 *  Created on: 23 kwi 2016
 *      Author: zabkiewi
 */

#include <time.h>
#include "typedef.h"
#include "chain.h"
#include "transactional.h"

#define QUIT 0x01

typedef struct _amount {
	uint8 * amount;
} AMOUNT;

/* returns amount of numbers in row */
uint32 amount_add(
		uint8 * amount1,
		uint8 * num_bytes1,
		uint8 * amount2,
		uint8 * num_bytes2
		) {
	uint32 num = 0;

	return num;
}



typedef struct personal_info {
	uint8 * name;
	uint8 * surname;

	uint8 ch[1];
} PRSNL_NFO;

typedef struct _transfer {
	time_t type;
} TRNSFR;

typedef struct _transfer_lock {
	uint32 ttl;
	uint32 hold_id;
} TRNSFR_LOCK;

typedef struct _personal_account {

	PRSNL_NFO 	* personal_info;			/* personal informations */
	CHAIN 		* income_transfers;			/* transfers incoming */
	CHAIN 		* outgoing_transfers;		/* transfers outgoing */

	CHAIN		* queue_outgoing_t;			/* queue of outgoing transfers */

	/* part of the paxos agrement algorithm */
	LIST		* promises;
	LIST		* comitments;
	LIST		* my_promises;
	LIST		* my_comitments;
	LIST		* transfer_locks;			/* locks on transaction phase */

	uint64 sum_income;						/* sum of incoming amounts */
	uint64 sum_outcome;						/* sum of outgoing amounts */
	uint64 balance;							/* account balance */
} ACCNT;


uint32 calc_balance(ACCNT * const acct);
uint32 calc_sums(ACCNT * const acct);

static CHAIN * const trans_chain; /* transactional chain */
static void send_t(ACCNT * const account);
static void reciv_t(ACCNT * const account);
static void sync(ACCNT * const account);

static void send_t(ACCNT * const account) {
	void * data;
	uint32 elem_size;
	while(account->queue_outgoing_t->first) {
		elem_size = chain_pop(account->queue_outgoing_t, data );

	}
}

static void reciv_t(ACCNT * const account) {

}

static void sync(ACCNT * const account) {

}

/* main function */
int main(int argc, char *argv[]) {
	uint32 cmd;

	printf("Starting new account engine....");

	// init account
	ACCNT * account;
	account = malloc(sizeof(ACCNT));
	account->personal_info 		= malloc(sizeof(PRSNL_NFO));

	// chains init
	account->income_transfers 	= malloc(sizeof(CHAIN));
	chain_init(account->personal_info, sizeof(TRNSFR));

	account->outgoing_transfers = malloc(sizeof(CHAIN));
	chain_init(account->personal_info, sizeof(TRNSFR));

	// init transaction chain
	chain_init(trans_chain, sizeof(Transaction));

	// reciv transfers
	while(1) {
		send_t(account);		/* send out transfers */
		reciv_t(account);	/* receive transfers from others */

		sync(account);

		// check if out
		if(cmd == QUIT) {
			break;
		}
		sleep(1);
	}

	printf("exiting....\n");

	return 0;
}

uint32 calc_balance(ACCNT * const acct) {
	return 0; 	// TODO cannot return zero
}

uint32 calc_sums(ACCNT * const acct) {
	return 0;
}


