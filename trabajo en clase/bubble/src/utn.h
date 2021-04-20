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

int myGets(char* pCadena, int len);
//int utn_getCaracter (char* pCaracter, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);
int utn_getNumero (int* pNumero, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);
int utn_cargarArrayFlotantesAleatorio (float* pArray, int len);
int utn_getFlotante (float* pNumFloat, char* pMensaje, char* pMensajeError, float min, float max, int reintentos);
int utn_getTexto (char* pCaracter, char* pMensaje, char* pMensajeError, int len, int reintentos);

int utn_getPrecio (float* pNumFloat, char* pMensaje, char* pMensajeError, float min, float max, int reintentos);
int utn_imprimirArrayFlotante(float* pArray, int len);
int utn_initArrayFlotante(float* pArray, int len, float valorInicial);
int utn_buscarMinimoArrayInt (int* pResultado, int array[],int limite);
int utn_buscarIndiceDelMinimoArrayInt (int* pResultadoIndice, int* pArray,int limite);
int utn_buscarMaximoArrayInt (int* pResultado, int* pArray,int limite);
int utn_imprimirArrayInt(int* pArray, int len);
int utn_cargarArrayIntSecuencial(int* pArray, int len);
int utn_borrarImparesArrayInt(int* pArray, int len);
int utn_promediarArrayInt(float* pResultado, int array[], int len);
int utn_ordenarArrayInt(int* pArray, int len);
#endif /* UTN_H_ */
