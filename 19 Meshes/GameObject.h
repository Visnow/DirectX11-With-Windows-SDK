#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"


class GameObject
{
public:
	// ʹ��ģ�����(C++11)��������
	template <class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;

	GameObject();

	// ��ȡλ��
	DirectX::XMFLOAT3 GetPosition() const;
	
	//
	// ��ȡ��Χ��
	//

	DirectX::BoundingBox GetLocalBoundingBox() const;
	DirectX::BoundingBox GetBoundingBox() const;
	//
	// ����ģ��
	//
	
	void SetModel(Model&& model);
	void SetModel(const Model& model);

	//
	// ���þ���
	//

	void SetWorldMatrix(const DirectX::XMFLOAT4X4& world);
	void SetWorldMatrix(DirectX::FXMMATRIX world);


	// ���ƶ���
	void Draw(ComPtr<ID3D11DeviceContext> deviceContext, BasicObjectFX& effect);

private:
	Model mModel;												// ģ��
	DirectX::XMFLOAT4X4 mWorldMatrix;							// �������

};


#endif

