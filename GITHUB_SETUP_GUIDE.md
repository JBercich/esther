# How to Create GitHub Issues and Milestone

This guide explains how to create the milestone and issues for the SDL3 and OpenGL Game Engine Setup using the provided documentation files.

## Step 1: Create the Milestone

1. Navigate to your GitHub repository: https://github.com/JBercich/esther
2. Click on the "Issues" tab
3. Click on "Milestones" 
4. Click "New milestone"
5. Use the information from `MILESTONE.md`:
   - **Title**: SDL3 and OpenGL Game Engine Setup
   - **Description**: Copy the description and goals from MILESTONE.md
   - **Due date**: (Optional) Set based on your timeline
6. Click "Create milestone"

## Step 2: Create the Issues

For each issue in `ISSUES.md`, create a new GitHub issue:

### Issue #1: Set up CMake build system with SDL3 integration

1. Go to Issues → New Issue
2. **Title**: Set up CMake build system with SDL3 integration
3. **Description**: Copy from ISSUES.md, including:
   - Description
   - Learning Resources
   - Tasks (as checkboxes)
   - Acceptance Criteria
   - Logging Requirements
   - Implementation Notes
4. **Labels**: Add labels like `enhancement`, `cmake`, `sdl3`, `setup`
5. **Milestone**: Select "SDL3 and OpenGL Game Engine Setup"
6. **Assignees**: Assign to yourself
7. Click "Submit new issue"

### Issue #2: Configure OpenGL context and shader pipeline

Repeat the process with content from ISSUES.md:
- **Title**: Configure OpenGL context and shader pipeline
- **Labels**: `enhancement`, `opengl`, `graphics`
- **Milestone**: SDL3 and OpenGL Game Engine Setup

### Issue #3: Implement logging system (spdlog integration)

- **Title**: Implement logging system (spdlog integration)
- **Labels**: `enhancement`, `logging`, `infrastructure`
- **Milestone**: SDL3 and OpenGL Game Engine Setup
- **Note**: Some groundwork for this is already in place (Logger.hpp)

### Issue #4: Create basic window and rendering loop

- **Title**: Create basic window and rendering loop
- **Labels**: `enhancement`, `game-loop`, `sdl3`
- **Milestone**: SDL3 and OpenGL Game Engine Setup

### Issue #5: Add shader compilation and management system

- **Title**: Add shader compilation and management system
- **Labels**: `enhancement`, `shaders`, `opengl`
- **Milestone**: SDL3 and OpenGL Game Engine Setup

### Issue #6: Set up resource management for assets

- **Title**: Set up resource management for assets
- **Labels**: `enhancement`, `resources`, `architecture`
- **Milestone**: SDL3 and OpenGL Game Engine Setup

### Issue #7: Create example shaders (vertex and fragment)

- **Title**: Create example shaders (vertex and fragment)
- **Labels**: `enhancement`, `shaders`, `examples`
- **Milestone**: SDL3 and OpenGL Game Engine Setup
- **Note**: Basic shaders are already created in assets/shaders/

### Issue #8: Documentation and learning resources compilation

- **Title**: Documentation and learning resources compilation
- **Labels**: `documentation`, `enhancement`
- **Milestone**: SDL3 and OpenGL Game Engine Setup
- **Note**: LEARNING_RESOURCES.md has been created as a starting point

## Step 3: Set Issue Dependencies (Optional)

After creating all issues, you can add dependencies in issue descriptions:

- Issue #1 is prerequisite for most others
- Issue #2 depends on Issue #1
- Issue #4 depends on Issues #1, #2, and #3
- Issue #5 depends on Issues #2 and #6
- Issue #7 depends on Issue #5

Add notes like "Depends on #1, #2" in the issue descriptions.

## Step 4: Organize with Projects (Optional)

You can create a GitHub Project board to track progress:

1. Go to Projects → New Project
2. Choose "Board" layout
3. Add columns: To Do, In Progress, Review, Done
4. Add all issues to the board
5. Move issues through columns as you progress

## Using the Issues for Development

### Work Order

Follow the recommended implementation order from ISSUES.md:
1. Issue #3 (Logging) - Enables debugging
2. Issue #1 (CMake/SDL3) - Foundation
3. Issue #2 (OpenGL) - Graphics capability
4. Issue #4 (Game Loop) - Framework
5. Issue #6 (Resources) - Asset loading
6. Issue #5 (Shaders) - Rendering system
7. Issue #7 (Examples) - Demonstrations
8. Issue #8 (Documentation) - Knowledge capture

### As You Work

1. **Start an issue**: Assign it to yourself, move to "In Progress"
2. **Check off tasks**: Update checkboxes as you complete tasks
3. **Log progress**: Add comments with what you learned
4. **Ask questions**: Use issue comments if you get stuck
5. **Reference commits**: Mention issue numbers in commits (e.g., "Fixes #3")
6. **Close when done**: Reference the closing commit

### Example Commit Messages

```bash
git commit -m "Add SDL3 integration to CMake (#1)"
git commit -m "Implement shader class with error handling (#5)"
git commit -m "Complete basic game loop - Fixes #4"
```

## Tips

- **Break down large issues**: If an issue feels too big, create sub-issues
- **Document as you go**: Add notes about problems and solutions in issue comments
- **Celebrate progress**: Close issues promptly when done
- **Share learnings**: Comment on issues with resources you found helpful
- **Stay organized**: Keep the milestone up to date with progress

## What's Already Done

This PR has already created:
- ✅ MILESTONE.md - Milestone specification
- ✅ ISSUES.md - Detailed issue descriptions
- ✅ LEARNING_RESOURCES.md - Comprehensive learning materials
- ✅ Logger.hpp - Basic logging infrastructure
- ✅ Example shaders (basic.vert/frag, lit.vert/frag)
- ✅ Shader documentation (assets/shaders/README.md)
- ✅ Updated main.cpp with TODOs

## Next Steps

1. Create the milestone on GitHub (use MILESTONE.md)
2. Create all 8 issues on GitHub (use ISSUES.md)
3. Start with Issue #3 (Logging) to get spdlog integrated
4. Then proceed with Issue #1 (CMake/SDL3)
5. Continue through issues in the recommended order
6. Use LEARNING_RESOURCES.md whenever you need help

Happy coding! 🚀
