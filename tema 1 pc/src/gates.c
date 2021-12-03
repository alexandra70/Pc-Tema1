#include "gates.h"

#include <stdio.h>
#include <assert.h>

/* Task 1 - Bit by Bit */

uint8_t get_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint8_t res = -1;

    /* TODO
     *
     * "res" should be 1 if the bit is active, else 0
     */
    

    int help_mask;
    int j;

    for (j = 0; j <= i; j++) {
        //calc sa vad dc e bitul ala pus rau sau nu
        help_mask = 1 << j;
        int bit_activ = 0;
        bit_activ = nr & help_mask;
        if (bit_activ == help_mask)
            res = 1;
        else
            res = 0;
    }
    return res;
}


uint64_t flip_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit flipped
     */
    
   
    uint64_t mask;
    uint64_t copy_nr = nr;
    

    mask = 1UL << i;
    
    copy_nr = nr ^ mask;

    res = copy_nr;

    return res;
}



uint64_t activate_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = 0xFF;

    /* TODO
     *
     * Return the "nr" with the ith bit "1"
     */

    uint64_t mask;
   
    mask = 1UL << i;
    nr = nr | mask;
    res = nr;
    


    return res;
}


uint64_t clear_bit(uint64_t nr, uint8_t i)
{
    assert(i <= 8 * sizeof nr);

    uint64_t res = -1;

    /* TODO
     *
     * Return the "nr" with the ith bit "0"
     */
    uint64_t mask = 1UL << i;
    uint64_t not = ~mask;
    res = not & nr;
    return res;
}


/* Task 2 - One Gate to Rule Them All */

uint8_t nand_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    return !(a & b);
}


uint8_t and_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the and gate */

    uint8_t x = !(nand_gate(a, b));

    res = x;

    return res;
}


uint8_t not_gate(uint8_t a)
{
    assert (a == 0 || a == 1);

    uint8_t res = -1;

    /* TODO - Use the nand gate to implement the not gate */

    uint8_t x = (nand_gate(a, a));

    res = x;

    return res;
}


uint8_t or_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the or gate */

    uint8_t x = not_gate(a) & not_gate(b);

    //int y = not_gate(x);

    res = not_gate(x);

    return res;
}


uint8_t xor_gate(uint8_t a, uint8_t b)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);

    uint8_t res = -1;

    /* TODO - Use the previously defined gates to implement the xor gate */

    uint8_t x = and_gate(a, not_gate(b));
    uint8_t y = and_gate(not_gate(a), b);
    uint8_t z = or_gate(x, y);

    //res = a ^ b;
    res = z;

    return res;
}


/* Task 3 - Just Carry the Bit */

uint8_t full_adder(uint8_t a, uint8_t b, uint8_t c)
{
    assert (a == 0 || a == 1);
    assert (b == 0 || b == 1);
    assert (c == 0 || c == 1);

    uint8_t res = -1;

    /* TODO - implement the full_adder using the previous gates
     * Since the full_adder needs to provide 2 results, you should
     * encode the sum bit and the carry bit in one byte - you can encode
     * it in whatever way you like
     */
  
    //0000 00cs;
    //uint8_t suma;
    //suma = or_gate(or_gate(a, b), c);
    //return (uint8_t)(a+b+c);
    //res = suma;
    //return res;

    //return (uint8_t)(a + b + c);
    res = a + b + c;
    return res;
}

uint64_t ripple_carry_adder(uint64_t a, uint64_t b)
{
    uint64_t res = -1;
   
    /* TODO
     * Use the full_adder to implement the ripple carry adder
     * If there is ANY overflow while adding "a" and "b" then the
     * result should be 0
     */

    res = 0;

    uint8_t k = 0;//ce cifra e acum
    uint8_t c = 0, aux;
    
    while (a != 0 || b != 0 || c != 0) {


        if (k > 63) {
            return 0UL;
        }

        aux = full_adder((uint8_t)a % 2, (uint8_t)b % 2, c);//???
        res += ((uint64_t)aux % 2) << k; // suma din aux 
        c = aux / 2;
        k++;
        a = a / 2;
        b = b / 2;
    }

    
    return res;
}
