//--------------------------------------------------------------------------------------
// Copyright 2015 Intel Corporation
// All Rights Reserved
//
// Permission is granted to use, copy, distribute and prepare derivative works of this
// software for any purpose and without fee, provided, that the above copyright notice
// and this statement appear in all copies.  Intel makes no representations about the
// suitability of this software for any purpose.  THIS SOFTWARE IS PROVIDED "AS IS."
// INTEL SPECIFICALLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, AND ALL LIABILITY,
// INCLUDING CONSEQUENTIAL AND OTHER INDIRECT DAMAGES, FOR THE USE OF THIS SOFTWARE,
// INCLUDING LIABILITY FOR INFRINGEMENT OF ANY PROPRIETARY RIGHTS, AND INCLUDING THE
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  Intel does not
// assume any responsibility for any errors which may appear in this software nor any
// responsibility to update it.
//
//--------------------------------------------------------------------------------------

#ifndef AABBOXRASTERIZERAVXMT_H
#define AABBOXRASTERIZERAVXMT_H

#include "AABBoxRasterizerAVX.h"

class AABBoxRasterizerAVXMT : public AABBoxRasterizerAVX
{
	public:
		AABBoxRasterizerAVXMT();
		~AABBoxRasterizerAVXMT();

		struct PerTaskData
		{
			UINT idx;
			AABBoxRasterizerAVXMT *pAABB; 
		};

		PerTaskData mTaskData[2];
		void TransformAABBoxAndDepthTest(CPUTCamera *pCamera, UINT idx);
		void WaitForTaskToFinish(UINT idx);
		void ReleaseTaskHandles(UINT idx);

	private:
		static void TransformAABBoxAndDepthTest(VOID* pTaskData, INT context, UINT taskId, UINT taskCount);
		void TransformAABBoxAndDepthTest(UINT taskId, UINT taskCount, UINT idx);
};

#endif //AABBOXRASTERIZERAVXMT_H