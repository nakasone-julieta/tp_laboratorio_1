/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: julieta_enee
 */

#ifndef UTN_H_
#define UTN_H_

int utn_dividirFloat (float* pResultado, float dividendo, float divisor);
int utn_multiplicarFloat (float* pResultado, float factor1, float factor2);
int utn_sumarFloat (float* pResultado, float sumando1, float sumando2);
int utn_restarFloat (float* pResultado, float minuendo, float sustraendo);

int utn_getInt (int* pNumero, char* pMensaje, char* pMensajeError,int min, int max, int reintentos);
int utn_getFloat(float *pDecimal,char*pMensaje,char*pMensajeError, float min, float max,int reintentos);
int utn_getChar(char* pCaracter, char* pMensaje, char* pMensajeError,char min, char max, int reintentos);

int utn_imprimirArray(int array[], int len);
int utn_promediarArray(float* pResultado, int array[], int len);
int utn_sumarArray(float* pResultado, int array[], int len);
int utn_buscarMinimoArrayInt (int array[],int limite, int* pResultado);
int utn_buscarMaximoArrayInt (int* pArray,int limite, int* pResultado);
int utn_buscarIndiceDelMinimoArrayInt (int* pArray,int limite, int* pResultadoIndice);
int utn_validarQueSeaNumeroArray(char texto[]);
int utn_ordenarArrayAscendente( int array[], int limite);
int utn_ordenarArrayDescendente( int array[], int limite);
#endif /* UTN_H_ */
