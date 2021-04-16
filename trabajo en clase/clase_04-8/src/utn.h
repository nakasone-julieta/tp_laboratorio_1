/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#ifndef UTN_H_
#define UTN_H_

int utn_sumarFloat (float* pResultado, float sumando1, float sumando2);
int utn_restarFloat (float* pResultado, float minuendo, float sustraendo);
int utn_dividirFloat (float* pResultado, float dividendo, float divisor);
int utn_multiplicarFloat (float* pResultado, float factor1, float factor2);
int utn_factorialFloat(float* pResultado, float numero);

int utn_getCaracter (char* pCaracter, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);
int utn_getNumero (int* pNumero, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);
int utn_getFlotante (float* pNumFloat, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);

#endif /* UTN_H_ */
