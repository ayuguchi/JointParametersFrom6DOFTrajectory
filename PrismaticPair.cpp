// PrismaticPair.cpp
#include "PrismaticPair.h"

void PrismaticPair::Estimation(std::vector<MotionMatrixd > &dest,
					  const std::vector<MotionMatrixd > &src, EstError &dest2)
{
    std::vector<MotionMatrixd > interTrj;
    /* �f�[�^�̍폜 */
    dest.clear();
    param.clear();
    /* �p�����[�^���� */
    EstOri0Param(interTrj, src, dest2.rotDiv);
    /* �p�����[�^���� */
    EstOri0Loc1Param(dest, interTrj, dest2.transDiv);
}

/* ���i����
 * @param src : 1=����� 0=�Ώە��� */
Eigen::Vector3d PrismaticPair::TranslationDirection(int src) const
{
    assert(0 <= src && src < 2);
    return param[src];
}

/* print parameter */
void PrismaticPair::Print(std::ostream &o) const
{
    o << "Target Object: " << param[0] << std::endl;
    o << "Base Object: " << param[1] << std::endl;
}

std::ostream& operator<<(std::ostream &o, const PrismaticPair &src)
{
    src.Print(o);
    return o;
}
