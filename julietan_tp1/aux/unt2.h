/*
 * unt2.h
 *
 *  Created on: 15 abr. 2021
 *      Author: julieta_enee
 */

#ifndef UNT2_H_
#define UNT2_H_

int utn_getChar (char* pCaracter, char* pMensaje, char* pMensajeError, char min, char max, int reintentos);
int utn_multiplicarFloat (float* pResultado, float factor1, float factor2);
int utn_sumarFloat (float* pResultado, float sumando1, float sumando2);
int utn_restarFloat (float* pResultado, float minuendo, float sustraendo);

int utn_getInt (int* pNumero, char* pMensaje, char* pMensajeError,int min, int max, int reintentos);
int utn_getFloat(float *pDecimal,char*pMensaje,char*pMensajeError, float min, float max,int reintentos);
int utn_getChar(char* pCaracter, char* pMensaje, char* pMensajeError,char min, char max, int reintentos);
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int min, int max, int reintentos);

int utn_imprimirArray(int array[], int len); //int
int utn_imprimirArrayChar(int array[],int len);
int utn_promediarArray(float* pResultado, int array[], int len);
int utn_sumarArray(float* pResultado, int array[], int len);
int utn_buscarMinimoArrayInt (int* pArray,int limite, int* pResultado);
int utn_buscarMaximoArrayInt (int* pArray,int limite, int* pResultado);
int utn_buscarIndiceDelMinimoArrayInt (int* pArray,int limite, int* pResultadoIndice);
int utn_validarQueSeaNumero(char texto[]);
#endif /* UNT2_H_ */
