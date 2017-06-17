#include "wingen.h"
#include "QR_Encode.h"

extern "C" int QREncodeData(int level, int version,
    unsigned char *data, int len, unsigned char *buff, int size)
{
	CQR_Encode *pQR_Encode = new CQR_Encode;
	if(pQR_Encode->EncodeData(level, version, FALSE, -1, data, len)) {
		if( pQR_Encode->m_nSymbleSize * pQR_Encode->m_nSymbleSize >
		    size)
			return (0);
		for(int i = 0; i < pQR_Encode->m_nSymbleSize; ++i)
			for(int j = 0; j < pQR_Encode->m_nSymbleSize; ++j)
				buff[i*pQR_Encode->m_nSymbleSize + j] = 
				    pQR_Encode->m_byModuleData[i][j];
		delete pQR_Encode;
		return (pQR_Encode->m_nSymbleSize*pQR_Encode->m_nSymbleSize);
	}
	delete pQR_Encode;
	return (0);
}
