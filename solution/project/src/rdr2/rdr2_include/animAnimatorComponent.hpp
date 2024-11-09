#pragma once

#include "base.hpp"

#include "AnimIdleBodyTypes.hpp"
#include "crExpressions.hpp"
#include "hlthMsgInjure.hpp"
#include "rdrAnimation.hpp"
#include "Vector3.hpp"
#include "Matrix34.hpp"
#include "sagMsgAttachmentImpact.hpp"

namespace rdr2
{
	class animAnimatorComponent
	{
	public:
		void ResetMembers(bool param_1)
		{
			sigs::animAnimatorComponent_ResetMembers.call<void>(this, param_1);
		}

		void InitAnimator()
		{
			sigs::animAnimatorComponent_InitAnimator.call<void>(this);
		}

		void DetermineBodyType()
		{
			sigs::animAnimatorComponent_DetermineBodyType.call<void>(this);
		}

		void StopParameterizedMotion()
		{
			sigs::animAnimatorComponent_StopParameterizedMotion.call<void>(this);
		}

		bool IsCurrentAnimFadeOut()
		{
			return sigs::animAnimatorComponent_IsCurrentAnimFadeOut.call<bool>(this);
		}

		void StopCurrentAnim(bool param_1)
		{
			sigs::animAnimatorComponent_StopCurrentAnim.call<void>(this, param_1);
		}

		bool ScheduleAnimation(rdrAnimation *param_1, bool param_2, float param_3, float param_4, float param_5, int param_6, float param_7)
		{
			return sigs::animAnimatorComponent_ScheduleAnimation.call<bool>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7);
		}

		void PoseAndUpdateHeadTurn(float param_1)
		{
			sigs::animAnimatorComponent_PoseAndUpdateHeadTurn.call<void>(this, param_1);
		}

		bool DetermineAndLoadNextIdle(AnimIdleBodyTypes param_1)
		{
			return sigs::animAnimatorComponent_DetermineAndLoadNextIdle.call<bool>(this, param_1);
		}

		void Shutdown()
		{
			sigs::animAnimatorComponent_Shutdown.call<void>(this);
		}

		bool IsAnimationsLoaded()
		{
			return sigs::animAnimatorComponent_IsAnimationsLoaded.call<bool>(this);
		}

		bool ScheduleExpression(crExpressions *param_1, float param_2, float param_3)
		{
			return sigs::animAnimatorComponent_ScheduleExpression.call<bool>(this, param_1, param_3);
		}

		animAnimatorComponent *NotifyInjured(hlthMsgInjure *param_1)
		{
			return sigs::animAnimatorComponent_NotifyInjured.call<animAnimatorComponent *>(this, param_1);
		}

		void UpdateActionTreeGaitMixer(Vector3 *param_1)
		{
			sigs::animAnimatorComponent_UpdateActionTreeGaitMixer.call<void>(this, param_1);
		}

		void InitFromSkeleton()
		{
			sigs::animAnimatorComponent_InitFromSkeleton.call<void>(this);
		}

		void UpdatePM()
		{
			sigs::animAnimatorComponent_UpdatePM.call<void>(this);
		}

		void EnableRepulsion(float param_1, Matrix34 *param_2)
		{
			sigs::animAnimatorComponent_EnableRepulsion.call<void>(this, param_1, param_2);
		}

		void UpdateCharacterAnimation(int param_1, float param_2, float param_3)
		{
			sigs::animAnimatorComponent_UpdateCharacterAnimation.call<void>(this, param_1, param_2, param_3);
		}

		void HandleAttachmentImpact(sagMsgAttachmentImpact *param_1)
		{
			sigs::animAnimatorComponent_HandleAttachmentImpact.call<void>(this, param_1);
		}
	};
}