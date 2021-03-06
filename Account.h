/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Banking System                */
/*  Author:   Christine Laurendeau                 */
/*  Date:     08-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Customer.h"
#include "defs.h"

class Account
{
  public:
    Account(Customer*, AcctType=GENERAL);
    AcctType   getAcctType();
    int        getAcctNum();
    Customer*  getCustomer();        
    void       getCust();
    float      getBalance();
    void       setBalance(float);
  private:
    static int nextAcctNum;
    AcctType   acctType;
    int        acctNum;
    Customer   *cust;
    float      balance;
};

#endif
