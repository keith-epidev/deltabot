Risk Analysis
=============

Risk mitigation is one of the most important aspects of managing a project. Possible predicted risks should be actively avoided. However not all are are forseen or are avoidable, in such case we should attempt to minimise the impact.

List of risks
-------------

| Risk (event)                     | Likelihood (H/M/L) | Impact (H/M/L) | Action |
|──────────────────────────────────|────────────────────|────────────────|────────|
|──────────────────────────────────|────────────────────|────────────────|────────|
| Development starts late          | M                  | L              |      2 |
| Schematics Incorrect             | M                  | L              |      1 |
| PCB Incorrect                    | M                  | L              |      1 |
| Unobtainable parts               | H                  | L              |      3 |
| Components break                 | H                  | M              |      3 |
| Underestimate Project time frame | M                  | H              |      2 |
| Underestimate Complexity         | H                  | H              |      4 |
| Implementation does not function | M                  | M              |      1 |
| Incomplete project threat        | L                  | H              |      4 |
| Code is lost / corrupted         | L                  | L              |      5 |
| Hardware issues                  | L                  | M              |      1 |
|──────────────────────────────────|────────────────────|────────────────|────────|
			List of possible risks


List of actions
---------------

| Action | Comment                                                                                                         |
|────────|─────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
|────────|─────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
|      1 | Diagnose and debug, attempt to develop work around depending on project stage. Redesign if problem is critical. |
|      2 | Adjust Gantt chart, design new tactics and re-prioritise if required.                                           |
|      3 | Obtain new components. If unavailable or time frame does not permit, attempt to use alternative.                |
|      4 | Discontinue development on selected components. Adopt complete and tested consumer alternatives.                |
|      5 | Pull latest commit from off site Git repository server. Backups should be made nightly.                         |
|────────|─────────────────────────────────────────────────────────────────────────────────────────────────────────────────|
				List of actions

Mitigated Risks
---------------

During the project a few events were mitigated with their associated actions. The following paragraphs discuss what occurred and how it was handled.


 *Schematics Incorrect* The first revision had many issues. All were able to be averted during the prototyping stage by making modifications to the PCB. All current issues were amended on the revision 2 board.

 *Components break* 4 Stepper drivers were damaged due to a poor PCB design. The new revision fixed these issues.

 *Underestimate Project time frame* Deadlines were met by shifting priorities around. An extension was later required for the project report.

 *Incomplete Project threat* Continued project development after final university deliverables have been met.

 *Hardware issues* Design kept improving and complete reworks were undertaken.

 *Code is corrupted* The current fork of code was in a non functioning state for the final presentation. Using Git as version control, I was able to checkout a previous working state ready for the presentation.



