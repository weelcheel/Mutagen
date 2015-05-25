///////////////////////////////////////////////////////////
//  USkillTree.h
//  Implementation of the Class USkillTree
//  Created on:      25-May-2015 17:22:32
//  Original author: sam
///////////////////////////////////////////////////////////

#if !defined(EA_2D4BF1FF_52DC_4094_A2C9_64ED581955F4__INCLUDED_)
#define EA_2D4BF1FF_52DC_4094_A2C9_64ED581955F4__INCLUDED_

class USkillTree
{

public:
	USkillTree();
	virtual ~USkillTree();

	void SelectNode(USkillTreeNode* nodeToSelect);
	void UnlockNode(USkillTreeNode* nodeToSelect);

};
#endif // !defined(EA_2D4BF1FF_52DC_4094_A2C9_64ED581955F4__INCLUDED_)
