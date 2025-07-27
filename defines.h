//defines.h
//macros.s

#ifndef _DEFINES_H
#define _DEFINES_H

// Set a specific bit in a word (register) to 1
#define SETBIT(WORD, BITPOS) ((WORD) |= (1 << (BITPOS)))

// Set a specific bit in a word to 1 and clear all other bits
#define SSETBIT(WORD, BITPOS) ((WORD) = (1 << (BITPOS)))

// Clear a specific bit in a word (set it to 0)
#define CLRBIT(WORD, BITPOS) ((WORD) &= (~(1 << (BITPOS))))

// Toggle (complement) a specific bit in a word
#define CPLBIT(WORD, BITPOS) ((WORD) ^= (1 << (BITPOS)))

// Read the value of a specific bit in a word
#define READBIT(WORD, BITPOS) (((WORD) >> (BITPOS)) & 1)

// Read a nibble (4 bits) from a word starting at a specific bit position
#define READNIBBLE(WORD, SBITPOS) (((WORD) >> (SBITPOS)) & 0xF)

// Write a specific bit value (0 or 1) to a word at a given bit position
#define WRITEBIT(WORD, BITPOS, BIT) \
    ((WORD) = ((WORD) & (~(1 << (BITPOS)))) | ((BIT) << (BITPOS)))

// Write a pair of bits (2 bits) to a word at a given bit position
#define WRITEPAIRBIT(WORD, BITPAIRPOS, PAIRBIT) \
    ((WORD) = ((WORD) & (~(3 << (BITPAIRPOS)))) | ((PAIRBIT) << (BITPAIRPOS)))

// Write a nibble (4 bits) to a word at a given starting bit position
#define WRITENIBBLE(WORD, SBITPOS, NIBBLE) \
    ((WORD) = ((WORD) & (~(0xF << (SBITPOS)))) | ((NIBBLE) << (SBITPOS)))

// Write a byte (8 bits) to a word at a given starting bit position
#define WRITEBYTE(WORD, SBITPOS, BYTE) \
    ((WORD) = ((WORD) & (~(0xFF << (SBITPOS)))) | ((BYTE) << (SBITPOS)))

// Read a bit from one word and write it to a specific bit position in another word
#define READWRITEBIT(DWORD, WBIT, SWORD, RBIT) \
    ((DWORD) = ((DWORD) & (~(1 << (WBIT)))) | ((((SWORD) >> (RBIT)) & 1) << (WBIT)))

// Read a bit from one position in a word and write it to another position in the same word
#define READWRITEBIT2(WORD, WBIT, RBIT) \
    ((WORD) = ((WORD) & (~(1 << (WBIT)))) | ((((WORD) >> (RBIT)) & 1) << (WBIT)))

// Set a function (FUNC) for a given pin (PIN) in a word
#define SET_FUNC(WORD, PIN, FUNC) \
    ((WORD) = ((PIN) < 16) ? \
        ((WORD) & (~(3 << ((PIN) * 2)))) | ((FUNC) << ((PIN) * 2))) : \
        ((WORD) & (~(3 << (((PIN) - 16) * 2)))) | ((FUNC) << (((PIN) - 16) * 2))))

// Function definitions for SET_FUNC
#define FUN0 0
#define FUN1 1
#define FUN2 2
#define FUN3 3

#endif // _DEFINES_H
