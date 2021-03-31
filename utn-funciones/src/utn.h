/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getInt (int* pNumero, char* pMensaje, char* pMensajeError,int min, int max, int reintentos);
int utn_getFloat(float *pDecimal,char*pMensaje,char*pMensajeError, float min, float max,int reintentos);
int utn_getChar(char* pCaracter, char* pMensaje, char* pMensajeError,char min, char max, int reintentos);

int utn_imprimirArray(int array[], int len);
int utn_promediarArray(float* pResultado, int array[], int len);
#endif /* UTN_H_ */
