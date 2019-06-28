#include <stdio.h>

#include <opencog/atomspace/AtomSpace.h>
#include <opencog/atoms/execution/Instantiator.h>
#include <opencog/atoms/execution/GroundedObject.h>
#include <opencog/atoms/execution/GroundedObjectNode.h>
#include <opencog/atoms/core/NumberNode.h>
#include <opencog/atoms/base/Link.h>

using namespace opencog;

#define an atomspace.add_node
#define al atomspace.add_link
#define aa atomspace.add_atom

int main() {

    AtomSpace atomspace;

    al(INHERITANCE_LINK,
            an(CONCEPT_NODE, "apple-1"),
            an(CONCEPT_NODE, "red"));

    al(INHERITANCE_LINK,
            an(CONCEPT_NODE, "apple-2"),
            an(CONCEPT_NODE, "green"));

    Handle bind_link = al(GET_LINK,
            al(INHERITANCE_LINK,
            an(VARIABLE_NODE, "$APPLE"),
            an(CONCEPT_NODE, "red")));

    Instantiator inst(&atomspace);

    ValuePtr value = inst.execute(bind_link);
    std::cout << "Red apple is: " << value << "\n";

    return 0;
}