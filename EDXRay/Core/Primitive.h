#pragma once

#include "EDXPrerequisites.h"
#include "../ForwardDecl.h"

#include "BSDF.h"
#include "Math/Vector.h"
#include "Memory/RefPtr.h"

namespace EDX
{
	namespace RayTracer
	{
		class Primitive
		{
		private:
			RefPtr<TriangleMesh>	mpMesh;

			// Materials
			vector<RefPtr<BSDF>>	mpBSDFs;
			uint*					mpMaterialIndices;

		public:
			Primitive()
			{
			}
			~Primitive();

			void LoadMesh(const char* path,
				const BSDFType bsdfType = BSDFType::Diffuse,
				const Vector3& pos = Vector3::ZERO,
				const Vector3& scl = Vector3::UNIT_SCALE,
				const Vector3& rot = Vector3::ZERO);
			void LoadSphere(const float radius,
				const BSDFType bsdfType = BSDFType::Diffuse,
				const int slices = 64,
				const int stacks = 64,
				const Vector3& pos = Vector3::ZERO,
				const Vector3& scl = Vector3::UNIT_SCALE,
				const Vector3& rot = Vector3::ZERO);

			void PostIntersect(const Ray& ray, DifferentialGeom* pDiffGeom) const;
			const BSDF* GetBSDF(const uint triId) const;

			const TriangleMesh* GetMesh() const
			{
				return mpMesh.Ptr();
			}
		};
	}
}