#include <qobject.h>
#include <qthread.h>
#include <qmap.h>
#include <QMutex>
#include <QWaitCondition>

class TMO;
class TMOImage;
class TMOGUIImage;
class QMutex;
class QWaitCondition;

class TMOGUITransformation :
    public QThread
{
	Q_OBJECT
public:
	TMOGUITransformation(TMOGUIImage *);
	virtual ~TMOGUITransformation(void);
	static int ProgressBar(TMOImage* pImage, int part, int all);
	static int WriteLine(TMOImage* pImage, const wchar_t* text);
	int Assign(TMOImage *pImage);
	int SetTMO(TMO* pToneMap);
	int RefreshGUI();
	TMOImage *GetDest();
	int Cancel();
	QWaitCondition* refresh;
protected:
	void run();
	int iOperation;
	TMO* pTMO;
	QMutex mutex;
    QMutex runningMutex;
	QWaitCondition condition;
	TMOImage *pDst;
	TMOGUIImage* pImage;
	int retval;
	static QMap<TMOImage*, TMOGUITransformation*> mapLocal;
};
