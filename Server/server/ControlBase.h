#ifndef CONTROL_BASE_H_
#define CONTROL_BASE_H_

/*
 *
 *	Detail: ����������
 *   
 *  Created by hzd 2014-10-29
 *
 */
template<class IK,class IV>
class ControlBase
{
	typedef std::map<IK,IV*> ItemMapType;

public:

	ControlBase(){}

	~ControlBase(){}

	virtual svoid UpdateAll(suint32 now_time) = 0;

	// �ͷ�times�е��ڴ�����ڴ���佻���ӿ�����
	virtual svoid Release() = 0;

	virtual sbool Remove(IK k)
	{
		ItemMapType::iterator it = mItems.find(k);
		if(it == mItems.end())
			return false;
		mItems.erase(it);
		return true;
	}

protected:
	
	ItemMapType mItems;
};

#endif