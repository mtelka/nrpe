#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif
DH *get_dh512()
	{
	static unsigned char dh512_p[]={
		0xE5,0xB7,0x24,0xAC,0x52,0x84,0x30,0x25,0x24,0xF3,0x35,0xE2,
		0x68,0xC0,0x9B,0x9D,0x88,0x06,0x49,0x48,0xB6,0x8C,0xD7,0x8E,
		0x60,0x23,0x87,0x28,0xF0,0xEB,0xD4,0xBA,0x45,0xCC,0xD8,0x17,
		0x03,0x03,0x07,0xF4,0xD4,0x03,0x69,0x72,0x83,0x5D,0xC4,0xA4,
		0xC0,0x19,0x08,0x09,0x65,0xAF,0x08,0x67,0x2C,0x6B,0xDE,0x1E,
		0x13,0xC0,0x44,0x53,
		};
	static unsigned char dh512_g[]={
		0x02,
		};
	DH *dh;

	if ((dh=DH_new()) == NULL) return(NULL);
	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
	if ((dh->p == NULL) || (dh->g == NULL))
		{ DH_free(dh); return(NULL); }
	return(dh);
	}