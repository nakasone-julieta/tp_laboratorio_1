/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt (int* pNumero, char* pTexto, char* pError,int min, int max, int reintentos);
int utn_getChar(char* pCaracter, char* pTexto, char* pError,char min, char max, int reintentos);
int utn_getFloat(float *pDecimal,char*pTexto,char*pError, float minimo, float maximo,int reintento);
#endif /* UTN_H_ */
