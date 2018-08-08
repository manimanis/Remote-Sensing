// Common.h : Contient toutes les define, et les d�finitions de variables
// 
///////////////////////////////////////////////////////////////////////////////////////

#ifndef		__COMMON_H__
#define		__COMMON_H__

// D�finition d'un point du graphe
typedef struct {
	float x;
	float y;
}	HistoPointData;

// Liste des defines

// Les defines utilis�es pour dessiner les fl�ches
#define FLECHE_EXT		1
#define FLECHE_ORG		2

// Les defines utilis�es pour dessiner les quadrillages
#define QUADRILLAGE_X	1
#define	QUADRILLAGE_Y	2

// Les defines utilis�es pour les types de histogrammes
#define HISTO_COURBE	1
#define HISTO_DISCRET	2
#define HISTO_POINTS	3

// Les defines utilis�es pour choisir le type du graphique
#define PICTURE_HISTOGRAMME		1
#define CUMULATIF_HISTOGRAMME	2


// Liste de fonctions

// Tracage des fl�ches
void fleche(CDC *pDC, CRect rect, int type);
void sort(int count, CPoint pt[], BOOL x_ord);

#endif	//	__COMMON_H__